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
void solve()
{
	freopen("promote.in","r",stdin);freopen("promote.out","w",stdout);
   	int n=4;
   	ar<int,2> a[n];
   	int b[n];
   	int delta = 0;
   	for(int i = 0;n > i;i++) cin >> a[i][0] >> a[i][1];

   	for(int i = n-1;i>=0;i--)
   	{
   		delta = max(0ll,delta + a[i][1] - a[i][0]);
   		b[i] = delta;
   	}

   	for(int i = n-2;i>=0;i--) cout << b[n - i - 1] << endl;
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