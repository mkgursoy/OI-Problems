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
//102101
void solve()
{
   	int n;
   	cin >> n;
   	int a[n];
   	set<int> st;
   	for(int i = 0;n > i;i++)
   	{
   		cin >> a[i];
   	}
   	for(int i = 0;n-1>i;i++)
   	{
   		if(i >= 0 && a[i-1] == a[i+1]) st.insert(a[i-1]);
   		if(a[i] == a[i+1]) st.insert(a[i]);
   	}
   	if(!st.size()) cout << "-1";
   	else
   	{
   		for(auto it : st)
   		{
   			if(it != *st.begin())
   				cout << " ";

   			cout << it; 
   		}   		
   	}
   	
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	cin >> tt;
	while(tt--)
	{
		solve();
		if(tt != 0) cout << endl;
	} 

}