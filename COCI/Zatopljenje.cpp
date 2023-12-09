#include<bits/stdc++.h>
#include<array>
using namespace std;
#define int long long
#define local_test freopen("/Users/metinkasim/Documents/in.txt","r",stdin);freopen("/Users/metinkasim/Documents/out.txt","w",stdout);
const int mxN = 2e5 + 5;
int par[mxN];
int find(int x)
{
	if(par[x] == -1) return x;
	else
		return par[x] = find(par[x]);
}
int union_sets(int x,int y)
{
	x = find(x);
	y = find(y);

	if(x != y)
	{
		par[x] = y;
		return 1;
	}
	else
		return 0;
}
int32_t main()
{
	//local_test
	int n,q;
	cin >> n >> q;
	int a[n];
	array<int,2> sorted_a[n];
	array<int,2> Q[q];
	for(int i = 0;n > i;i++)
	{
		cin >> a[i];
		sorted_a[i] = {a[i] , i};
		par[i] = -1;
	}
	for(int i = 0;q > i;i++)
	{
		int x,y;
		cin >> x >> y;
		cin >> Q[i][0];
		Q[i][1] = i;
	}
	int ind = 0;
	int comp = 0;
	sort(sorted_a,sorted_a + n , greater<>());
	sort(Q , Q + q,greater<>());
	int ans[q];
	for(int i = 0;q > i;i++)
	{
		//cout << i << ": " << sorted_a[ind][0] << endl;
		while(n > ind && sorted_a[ind][0] > Q[i][0])
		{
			comp += 1;
			if(n-1 > sorted_a[ind][1] && a[sorted_a[ind][1] + 1] >= sorted_a[ind][0])
			{
				comp -= union_sets(sorted_a[ind][1] , sorted_a[ind][1] + 1);
			}
			if(0 < sorted_a[ind][1] && a[sorted_a[ind][1] - 1] >= sorted_a[ind][0])
			{
				comp -= union_sets(sorted_a[ind][1] , sorted_a[ind][1] - 1);
			}
			//cout << i <<  " COMP: " << comp << endl;
			ind++;

		}
		ans[Q[i][1]] = comp;
	}
	for(auto it : ans) cout << it << endl;

	
}