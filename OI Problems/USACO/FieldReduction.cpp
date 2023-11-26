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

void setIO(string name = "reduce") 
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
   	ar<int,2> a[n];
   	multiset<int> x;
   	multiset<int> y;
   	for(int i = 0;n > i;i++)
   	{
   		cin >> a[i][0] >> a[i][1];
   		x.insert(a[i][0]);
   		y.insert(a[i][1]);
   		
   	}

   	int ans = INF;
   	for(int i = 0;n > i;i++)
   	{
   		x.erase(x.find(a[i][0]));
   		y.erase(y.find(a[i][1]));

   		auto lb_x = x.begin() , lb_y = y.begin() , ub_x = x.end() , ub_y = y.end();
   		ans = min(ans , abs((*lb_y) - (*(--ub_y))) * abs((*lb_x) - (*(--ub_x))));
   		x.insert(a[i][0]);
   		y.insert(a[i][1]);
   		//cout << ans << endl;
   	}
   	cout << ans << endl;
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