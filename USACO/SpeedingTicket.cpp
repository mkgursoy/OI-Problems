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

void setIO(string name = "speeding") 
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
   	int n,m;
   	cin >> n >> m;
   	ar<int,2> signs[n];
   	ar<int,2> bessie[m];
   	int signs_array[105];
   	int bessie_array[105];
   	memset(signs_array,-1,sizeof(signs_array));
   	memset(bessie_array,-1,sizeof(bessie_array));
   	for(int i = 0;n > i;i++)
   	{
   		cin >> signs[i][0] >> signs[i][1];
   		if(i > 0)
   		{
   			signs[i][0] += signs[i-1][0];
   		}
   	} 
   	for(int i = 0;m > i;i++)
   	{
   		cin >> bessie[i][0] >> bessie[i][1];
   		if(i > 0)
   		{
   			bessie[i][0] += bessie[i-1][0];
   		}
   	}
   	for(int i = 0;m > i;i++)
   	{
   		for(int j = 0;bessie[i][0] > j;j++)
   		{
   			if(bessie_array[j] == -1) bessie_array[j] = bessie[i][1];
   		}
   	}
   	for(int i = 0;n > i;i++)
   	{
   		for(int j = 0;signs[i][0] > j;j++)
   		{
   			if(signs_array[j] == -1) signs_array[j] = signs[i][1];
   		}
   	}	
   	int ans = 0;
   	for(int i = 0;100 >= i;i++)
   	{
   		ans = max(ans , bessie_array[i] - signs_array[i]);
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