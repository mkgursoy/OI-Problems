/*
    Author:Matkap(prefixsumenjoyer23)
    
*/

#include <bits/stdc++.h>
#include <array>

using namespace std;

#define fr freopen("/Users/metinkasim/Documents/in.txt","r",stdin);freopen("/Users/metinkasim/Documents/out.txt","w",stdout);
#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()

int INF = 1e18;

int binpow(int base,int power)
{
	if(power == 1) return base;
	if(power == 0) return 1;
    
     if(power%2==1)
     {
     	 int a;
     	a = binpow(base,(power-1)/2);
     	return a*a*base;
     } 
     else
     {
     	 int a;
     	a = binpow(base,power/2);
     	return a*a;
     } 

}

const int mxN = 1e3 + 5 , mxQ = 1e5 + 5;
int par[mxN * mxN];
int a[mxN][mxN];
int ans1[mxQ];
int cur = 0;
int n,m,q;
ar<int,2> el[mxN * mxN];
ar<int,2> Q[mxQ];
int find(int a)
{
	if(par[a] == -1) return a;
	else
		return par[a] = find(par[a]);
}
void union_sets(int a,int b)
{
	a = find(a);
	b = find(b);

	if(a == b) return;
	par[a] = b;
	cur -= 1;
}
void solve()
{	
	memset(par,-1,sizeof(par));
   	cin >> n >> m;
   	for(int i = 0;n > i;i++)
   	{
   		for(int j = 0;m > j;j++)
   		{
   			cin >> a[i][j];
   			el[m * i + j] = {a[i][j] , m * i + j};
   		}
   	}
   	cin >> q;
   	for(int i = 0;q > i;i++)
   	{
   		int x;
   		cin >> x;
   		Q[i] = {x,i};
   	}

   	sort(el , el + m * n , greater<>());
   	sort(Q , Q + q , greater<>());
   	int ind = 0;
   	for(int i = 0;q > i;i++)
   	{
   		while(ind < m * n && el[ind][0] >= Q[i][0])
   		{
   			cur += 1;
   			int x = el[ind][1] / m;
   			int y = el[ind][1] % m;

   			if(el[ind][1] + m < m * n && a[x+1][y] >= el[ind][0])
   			{
   				union_sets(el[ind][1] , el[ind][1] + m);
   			}
   			if(el[ind][1] - m >= 0 && a[x-1][y] >= el[ind][0])
   			{
   				union_sets(el[ind][1] , el[ind][1] - m);
   			}
   			if((el[ind][1] + 1) % m && a[x][y+1] >= el[ind][0])
   			{
   				union_sets(el[ind][1] , el[ind][1] + 1);
   			}
   			if(el[ind][1] % m && a[x][y-1] >= el[ind][0])
   			{
   				union_sets(el[ind][1] , el[ind][1] - 1);
   			}
   			ind += 1;
   		}
   		ans1[Q[i][1]] = cur;
   	}

   	for(int i = 0;q > i;i++) cout << ans1[i] << endl;


}



int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	fr

	int t;
	t=1;
	//cin >> t;
	while(t--) solve();

}