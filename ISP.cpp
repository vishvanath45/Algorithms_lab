// Interval Scheduling Problem, non-weighted, here I have taken weight=0 

#include <bits/stdc++.h>
using namespace std;

int main()
{

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

// no. of test inputs
int t;
cin>>t;

// vector stores finish time, start time and weight 
vector< pair<int, pair<int,int> > > vc;

int a, b, c;
for(int i = 0 ; i < t ; i++)
{
	cin>> a >> b;
	c = 0;
	vc.push_back(make_pair(b, make_pair(a,c)));
}

int curr_max = vc[0].second.second;
int pst = vc[0].second.first;
int pft = vc[0].first;

int cst;
int cft;
int cp;

int cnt = 1;
for(int i = 1 ; i < vc.size() ; i++)
{
	cst = vc[i].second.first;
	cft = vc[i].first;
	cp = vc[i].second.second;

	if(cst >= pft)
	{
		cnt++;
		curr_max += cp;
		pst = cst;
		pft = cft;
	}
}

cout<<cnt;
// cout<<curr_max;

return 0;
}
