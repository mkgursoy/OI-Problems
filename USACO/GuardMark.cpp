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

int INF = 1e13;

void setIO(string name = "guard") 
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
ar<int,2> dp[(1 << 22)]; // dp[i][0] => safety,dp[i][1] => height
void solve()
{
	setIO();
   	int n,m;
   	cin >> n >> m;
   	ar<int,3> friends[n];  	 
   	int ans = 0;
   	for(int i = 0;n > i;i++)
   	{
   		cin >> friends[i][0] >> friends[i][1] >> friends[i][2];
   	}
   	dp[0][0] = INF;
   	dp[0][1] = 0;
   	for(int i = 1;(1 << n) > i;i++)
   	{
   		dp[i][0] = -1;
   		dp[i][1] = 0;
   		vector<ar<int,3>> vec;
   		for(int j = 0;n > j;j++)
   		{
   			if(i & (1 << j))
   			{
   				dp[i][1] += friends[j][0];
   				int prev = i ^ (1 << j);
   				dp[i][0] = max(dp[i][0] , min(dp[prev][0] - friends[j][1] , friends[j][2]));
   			}
   		}
   	}

   	int k = -1;
   	for(int i = 1;(1 << n) > i;i++) 
   	{
   		if(dp[i][1] >= m)
   		k = max(k,dp[i][0]);
   	}

   	if(k<0) cout << "Mark is too tall" << endl;
   	else
   		cout << k << endl;
}



int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//	fr

	int t;
	t=1;
	//cin >> t;
	while(t--) solve();

}