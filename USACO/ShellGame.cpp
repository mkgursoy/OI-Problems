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

void setIO(string name = "shell") 
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
	setIO();
	int n;
	cin >> n;
   	ar<int,3> a[n];
   	for(int i = 0;n > i;i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
   	int ans = 0;
   	for(int i = 1;3 >= i;i++)
   	{
   		int tmp_ans = 0;
   		int pebble_loc = i;
   		for(auto it : a)
   		{
   			if(pebble_loc == it[0]) pebble_loc = it[1];
   			else if(pebble_loc == it[1]) pebble_loc = it[0];

   			if(it[2] == pebble_loc) tmp_ans += 1;
   		}
   		ans = max(tmp_ans , ans);
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