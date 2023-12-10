/*
    Author:Matkap(prefixsumenjoyer23)
    
*/

#include <bits/stdc++.h>

using namespace std;
#define fr freopen("/Users/metinkasim/Documents/in.txt","r",stdin);freopen("/Users/metinkasim/Documents/out.txt","w",stdout);


#define int long long
#define endl "\n"
const int mod = 1e9+9;
#define all(x) x.begin(),x.end()

int mxn = 1e18;
int mnn = -mxn;

void outarr(int ans[],int n)
{
	for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
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
int gcd(int a, int b)
{

    if(b == 0) {
            return a;
    }
    else {
        return gcd(b, a % b);
    }
}
int lcm(int a,int b)
{
	return (a*b)/gcd(a,b);
}

void solve()
{
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
   	int n,m,k1;
   	cin >> n >> m >> k1;

   	int fj[n];
   	int fp[m];
   	for(int i = 0;n>i;i++) cin >> fj[i];
   	for(int i = 0;m>i;i++) cin >> fp[i];
   	sort(fj,fj+n,greater<>());
   	sort(fp,fp+m,greater<>());
   	int dp[n+1][m+1][k1+1];
   	memset(dp,0,sizeof(dp));
   	for(int i = 0;n >= i;i++)
   	{
   		for(int j = 0;m >= j;j++)
   		{
   			dp[i][j][0] = 1;
   		}
   	}

   	for(int i = 1;n >= i;i++)
   	{
   		for(int j = 1;m >= j;j++)
   		{
   			for(int k = 1;k1 >= k;k++)
   			{
   				dp[i][j][k] = dp[i-1][j][k] + dp[i][j-1][k] - dp[i-1][j-1][k];

   				if(fj[i-1] > fp[j-1])
   				{
   					dp[i][j][k] += dp[i-1][j-1][k-1];
   				}

   				dp[i][j][k] += mod;
   				dp[i][j][k] %= mod;
   			}
   		}
   	}

   	cout << dp[n][m][k1] << endl;
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


