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

void setIO(string name = "milkorder") 
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
//2 10 3 1
//_ 10 _ 8 _ _ 7 _ _ _
void solve()
{
	setIO();
   	int n,m,k;
   	cin >> n >> m >> k;
   	int hier[m];
   	int total[n];
   	int ind[n];
   	int mark[n];
   	memset(ind,-1,sizeof(ind));
   	memset(mark,-1,sizeof(mark));
   	memset(total,-1,sizeof(total));
   	for(int i = 0;m > i;i++) cin >> hier[i] , hier[i]-- , mark[hier[i]] = 1;
   	reverse(hier,hier+m);
   	for(int i = 0;k > i;i++)
   	{
   		int x,y;
   		cin >> x >> y;
   		x--,y--;
   		total[y] = x;
   		ind[x] = y;
   	}
   	if(ind[0] != -1)
   	{
   		cout << ind[0] + 1 << endl;
   		return;
   	}
   	if(mark[0] != -1)
   	{
   		reverse(hier,hier+m);
   		for(int i = 0,j = 0;m > j && n > i;i++,j++)
   		{
   			if(total[i] != -1)
   			{
   				j--;
   				continue;
   			}
   			if(ind[hier[j]] != -1) i = ind[hier[j]];
   			if(hier[j] == 0)
   			{
   				cout << i+1 << endl;
   				return;
   			}

   		}
   	}
   	for(int i = n-1,j = 0;m > j && i >= 0;i--,j++)
   	{
   		if(total[i] != -1)
   		{
   			j--;
   			continue;
   		}
   		if(ind[hier[j]] != -1) i = ind[hier[j]];
   		else total[i] = hier[j] , ind[hier[j]] = i;
   	}
   	for(int i = 0;n > i;i++)
   	{
   		if(total[i] == -1)
   		{
   			cout << i+1 << endl;
   			return;
   		}
   	}


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