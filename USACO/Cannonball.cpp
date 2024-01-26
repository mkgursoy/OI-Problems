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
void solve()
{
   	int n;
   	cin >> n;
   	int pos;
   	cin >> pos;
   	pos--;
   	int pow = 1;
   	int cnt = 0;
   	bool pos1 = true; //true if 1 -> n
   	ar<int,2> a[n];
   	for(int i = 0;n > i;i++)
   	{
   		cin >> a[i][0] >> a[i][1];
   		if(a[i][0] == 1) cnt++;
   	} 
   	int ans = 0;
   	bool hit_target = false;
   	int hit[n];
   	memset(hit,0,sizeof(hit));
   	bool before = false;
   	while(pos >= 0 && n > pos)
   	{
   		if(cnt == 0) break;
   		//cout << ans << " " << pos << endl;
   		if(a[pos][0] == 0)
   		{
   			if(a[pos][1] == 0)
   			{
   				if(before) break;
   				else
   					before = true;
   			}
   			else
   				before = false;
   			//cout << "0 CASE" << endl;
   			pow += a[pos][1];
   			pos1 = !pos1;
   		}
   		else
   		{
   			if(hit[pos] == 0)
   			{
   				if(a[pos][1] <= pow) ans++,hit[pos] = 23 , cnt--;
   			}
   			//cout << pos << endl;
   			
   		}

   		if(pos1) pos += pow;
   		else
   			pos -= pow;

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