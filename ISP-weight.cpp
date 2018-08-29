// Interval Scheduling Problem,weighted used dynamic programming
// http://pages.cs.wisc.edu/~shuchi/courses/787-F09/scribe-notes/lec3.pdf

#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
// no. of test inputs
int t;
cin>>t;
// vector stores start time, finish time and weight 

vector< pair<int, pair<int,int> > > vc;

int a, b, c;
for(int i = 0 ; i < t ; i++)
{
	cin>> a >> b >> c;
	vc.push_back(make_pair(a, make_pair(b,c)));
}


sort(vc.begin(), vc.end());

int no_overlap[t];


for(int i = 0 ; i < vc.size() ; i++)
{
	for(int j = i + 1 ; j < vc.size() ; j++)
	{
		if(vc[j].first >= vc[i].second.first)
		{
			no_overlap[i] = j;
			break;
		}
		else if( j == vc.size()-1 )
		{
			no_overlap[i] = -1;
		}
	}
}

no_overlap[vc.size()-1] = -1;


int ans[t+1];
ans[t] = -1;

for(int i = vc.size()-1 ; i >= 0 ; i--)
{
	int val = no_overlap[i];

	if(val != -1)
	{
		ans[i] = max(vc[i].second.second + ans[val] , ans[i+1]) ;
	}
	else
	{
		ans[i] = max(vc[i].second.second, ans[i+1]);
	}
}


cout<<ans[0];

return 0;

}

