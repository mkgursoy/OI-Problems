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
void solve()
{
   	int n,m,d,s;
   	cin >> n >> m >> d >> s;
   	ar<int,3> a[d];
   	ar<int,2> b[s];
   	for(int i = 0;d > i;i++)
   	{
   		cin >> a[i][1] >> a[i][2] >> a[i][0];
   	}
   	int max_time = INF;
   	for(int i = 0;s > i;i++)
   	{
   		cin >> b[i][1] >> b[i][0];
   		max_time = min(max_time , b[i][0]);
   	}
   	sort(a,a+d);
   	for(int i = 0;d > a[i][0];i++)
   	{
   		
   	}

}



int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	fr

	int t;
	t=1;
	cin >> t;
	while(t--) solve();

}