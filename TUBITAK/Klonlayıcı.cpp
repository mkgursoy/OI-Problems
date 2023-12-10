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
const int mod = 1e9 + 7;
void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char,int> hash;
	hash['A'] = 1;
	hash['T'] = 1e6;
	hash['U'] = 1e12;
	hash['M'] = -1-1e6-1e12;
	int sum = 0;
	int ans = 0;
	int ans2 = 0;
	map<int,ar<int,2>> vals;
	vals[0][0] = 1;
	vals[0][1] = -1;
	for(int i = 0;n > i;i++)
	{
		sum += hash[s[i]];
		ans += vals[sum][0];
		ans %= mod;
		if(vals[sum][1])
		ans2 = max(ans2,(i - vals[sum][1])/4);
		vals[sum][0] += 1;
		if(!vals[sum][1])
		vals[sum][1] = i;
		//cout << sum << endl;
	}

	cout << ans << " " << ans2 << endl;
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