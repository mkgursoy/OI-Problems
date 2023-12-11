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

void setIO(string name = "paintbarn") 
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
int pref[1005][1005];
void solve()
{
	setIO();
   	int n,m;
   	cin >> n >> m;
   	while(n--)
   	{
   		ar<int,2> p1,p2;
   		cin >> p1[0] >> p1[1] >> p2[0] >> p2[1];
   		pref[p1[0]][p1[1]]++;
   		pref[p1[0]][p2[1]]--;
   		pref[p2[0]][p2[1]]++;
   		pref[p2[0]][p1[1]]--;
   	}

   	int ans = 0;
   	for(int i = 0;1000 >= i;i++)
   	{
   		for(int j = 0;1000 >= j;j++)
   		{
   			if(i > 0)
   			{
   				pref[i][j] += pref[i-1][j];
   			}  			
   			if(j > 0)
   			{
   				pref[i][j] += pref[i][j-1];
   			}
   			if(i > 0 && j > 0)
   			{
   				pref[i][j] -= pref[i-1][j-1];
   			}
   			if(pref[i][j] == m) ans++;
   		}
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