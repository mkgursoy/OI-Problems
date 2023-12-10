/*
    Author:Matkap(prefixsumenjoyer23)
    
*/

#include <bits/stdc++.h>
#include<array>

using namespace std;
#define fr freopen("/Users/metinkasim/Documents/in.txt","r",stdin);freopen("/Users/metinkasim/Documents/out.txt","w",stdout);


#define int long long
#define endl "\n"
#define mod  998244353
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
	freopen("redistricting.in","r",stdin);
	freopen("redistricting.out","w",stdout);
	
   	int n,k;
   	cin >> n >> k;
   	string cows;
   	cin >> cows;

   	int pref[n+5];
   	pref[0] = 0;
   	for(int i = 1;n >= i;i++)
   	{
   		pref[i] = pref[i-1] + (cows[i-1] == 'H') - (cows[i-1] == 'G');
   	}


   	int dp[n+5];

   	multiset<int> dpvals;
   	multiset<int> dp_pref[300001];
   	//Not priority queue so we can remove elements.
   	dpvals.insert(0);
   	dp_pref[0].insert(0);
   	dp[0] = 0;
   	for(int i = 1;n >= i;i++)
   	{
   		

   		
   			int num = *(dpvals.begin());

   			if(*dp_pref[num].begin() < pref[i])
   			{
   				dp[i] = num;
   			}
   			else
   				dp[i] = num+1;
   		
   		
   		

   		dpvals.insert(dp[i]);
   		dp_pref[dp[i]].insert(pref[i]);


   		if(i >= k)
   		{
   			dpvals.erase(dpvals.find(dp[i-k]));
   			dp_pref[dp[i-k]].erase(dp_pref[dp[i-k]].find(pref[i-k]));
   		}

   	}
   	cout << dp[n] << endl;
   	


   	

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


