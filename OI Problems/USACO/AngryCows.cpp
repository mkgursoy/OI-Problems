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

void setIO(string name = "angry") 
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
//3 4 5 6 8 13
void solve()
{
	setIO();
   	int n;
   	cin >> n;
   	int a[n];
   	for(int i = 0;n > i;i++)
   	{
   		cin >> a[i];
   	}
   	sort(a,a + n);
   	int ans = 0;
   	for(int start = 0;n > start;start++)
   	{
   		int cnt = 1;
   		int radius = 1;
   		//Left:
   		for(int i = start - 1;i >= 0;i--)
   		{
   			if(a[i+1] - a[i] > radius) break;
   			int l = i;
   			while(l >= 0 && a[i+1] - a[l] <= radius) l-- , cnt++;
   			l++;  			
   			radius += 1;
   			i = l;
   		}
   		radius = 1;
   		//Right
   		for(int i = start + 1;n > i;i++)
   		{
   			if(a[i] - a[i-1] > radius) break;
   			int r = i;
   			while(n > r && a[r] - a[i-1] <= radius) r++ , cnt++;
   			r--;
   			radius += 1;
   			i = r;
   		}
   		ans = max(ans , cnt);
   		//cout << ans << endl;
   	}

   	cout << ans << endl;
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