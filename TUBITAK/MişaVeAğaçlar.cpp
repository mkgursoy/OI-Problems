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

int INF = 1e16;

void setIO(string name = "") 
{
	if (name.size())
	{
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
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
int findCost(string a,string b)
{
	//cout << a << " " << b << endl;
	int n = a.size();
	int m = b.size();
	int dp[n+1][m+1];
	dp[0][0] = 0;
	for(int i = 0;n >= i;i++)
	{
		for(int j = 0;m >= j;j++)
		{
			if(i == 0 && j == 0) continue;
			dp[i][j] = INF;
			if(i > 0) dp[i][j] = min(dp[i][j] , dp[i-1][j] + 1);
			if(j > 0) dp[i][j] = min(dp[i][j] , dp[i][j-1] + 1);
			if(i > 0 && j > 0) dp[i][j] = min(dp[i][j] , dp[i-1][j-1] + (a[i-1] != b[j-1]));
		}
	}
	return dp[n][m];
}
const int mxN = 1e5 + 7;
vector<int> adj[mxN];
map<int,string> val;
void solve()
{
   	int n,m;
   	cin >> n >> m;
   	for(int i = 0;m > i;i++)
   	{
   		int x,y;
   		cin >> x >> y;
   		adj[x].push_back(y);
   		adj[y].push_back(x);
   	}
   	for(int i = 0;n > i;i++)
   	{
   		string s;
   		cin >> s;
   		val[i+1] = s;
   	}
   	int sum = 0;
   	int vis[n+5];
   	memset(vis,0,sizeof(vis));
   	priority_queue<ar<int,2> , vector<ar<int,2>> , greater<ar<int,2>>> pq;
   	int x = 1;
   	for(int i = 0;adj[1].size() > i;i++)
   	{
   		int it = adj[1][i];
   		pq.push({findCost(val[1] , val[it]) , it});
   		//cout << val[1] << " " << val[it] << endl;
   	} 
   	vis[1] = 1;
   	while(n > x && pq.size())
   	{
   		ar<int,2> piv = pq.top();
   		vis[piv[1]] = 1;
   		pq.pop();
   		sum += piv[0];
   		for(auto it : adj[piv[1]])
   		{
   			if(!vis[it])
   			{
   				pq.push({findCost(val[piv[1]] , val[it]) , it});  				
   			}
   		}
   		x += 1;
   	}
   	cout << sum << endl;
}



int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	//fr

	int t;
	t=1;
	//cin >> t;
	while(t--) solve();

}