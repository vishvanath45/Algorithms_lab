#include <bits/stdc++.h>
using namespace std;

int main()
{

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	// edges
	int n;
	cin>>n;

	// vertices
	int k;
	cin>>k;

	vector<pair< int, pair<int,int> > > vc;

	int a,b,c;

	int parent[k];

	for(int i = 0 ; i < k ; i++)
		parent[i] = i;

	for(int i = 0 ; i < n ; i++)
	{	
		cin>>a>>b>>c;
		vc.push_back( make_pair(c, make_pair(a,b)) );
	}

	sort(vc.begin(), vc.end());

	// for(int i = 0 ; i < vc.size() ; i++)
	// {
	// 	cout<<vc[i].first<<" ";
	// }

	int weight = 0;

	for(int i = 0 ; i < vc.size() ; i++)
	{	
		int fval = vc[i].second.first;
		int sval = vc[i].second.second;
		//cout<<fval<<" "<<sval<<" ** \n";
		//cout<<parent[fval]<<" "<<parent[sval]<<" -- \n";
		if(parent[fval] != parent[sval])
		{
			cout<<fval<<" - "<<sval<<" ** \n";
			int pp = parent[sval];
			for(int j = 0 ; j < k ; j++)
			{
				if(parent[j] == pp)
					parent[j] = parent[fval];
			}
		weight += vc[i].first;
		}
		// for(int i = 0 ; i < k ; i++)
		// 	cout<<parent[i]<<" ";
		// 	cout<<"\n";
	}
	cout<<"Weight : "<<weight<<"\n";
	for(int i = 0 ; i < k ; i++)
		cout<<parent[i]<<" ";


	return 0;
}