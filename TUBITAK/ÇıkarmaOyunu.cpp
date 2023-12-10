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
const int mxN = 505,mxA = 1005;
int dp[mxN][mxN];
void solve()
{
 	int n;
 	cin >> n;
 	int a[n];
 	for(int i = 0;n > i;i++) cin >> a[i];
 	for(int i = 2;n > i;i++)
 	{
 		for(int j = 0;n - i > j;j++)
 		{
 			for(int k = j + 1;i + j >= k;k++)
 			{
 				dp[j][i + j] = max(dp[j][i + j] , dp[j][k-1] + dp[k][i + j] + a[j] * a[i+j]);
 			}
 		}
 	}
 	for(int i = 0;n > i;i++)
 	{
 		for(int j = 0;n > j;j++) cout << dp[i][j] << " ";
 		cout << endl;
 	}
 	cout << dp[0][n-1] << endl;
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