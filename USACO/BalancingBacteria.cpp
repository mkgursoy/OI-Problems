/*
    Author:Matkap(prefix_sum)
*/

#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()

const int INF = 1e17 , MOD = 1e9 + 7;

void setIO(string name = "") 
{
	if (name.size())
	{
		freopen((name + ".in").c_str(), "r", stdin); // For USACO
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
/*
	A çıkarılcak 0
	A B çıkarılcak A*2
	A B C çıkarılcak A*3 + B*2
*/
void solve()
{
   	int n;
   	cin >> n;
   	int a[n];
   	for(int i = 0;n > i;i++)
   	{
   		cin >> a[i];
   	}
   	int sum = 0;
   	int ans = 0;
   	int sum_till = 0;
   	for(int i = 0;n > i;i++)
   	{ 		
   		sum -= sum_till;
   		a[i] += sum;
   		ans += abs(a[i]);
   		sum_till += a[i];
   		sum -= a[i];
   		//cout << ans << " " << sum_till << " " << sum << endl;

   	}
   	cout << ans;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	//cin >> tt;
	while(tt--) solve();

}