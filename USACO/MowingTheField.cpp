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

void setIO(string name = "mowing") 
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
const int mxN = 2e3 + 5;
int field[mxN * 2][mxN * 2];
void solve()
{
	setIO();
   	int n;
   	cin >> n;
   	int curx = mxN;
   	int cury = mxN;
   	int timer = 1;
   	int ans = INF;
   	while(n--)
   	{
   		char dir;
   		int steps;
   		cin >> dir >> steps;

   		if(dir == 'N')
   		{
   			for(int i = 0;steps > i;i++)
   			{   				
   				cury += 1;
   				if(field[curx][cury] != 0) ans = min(ans,timer - field[curx][cury]);
   				field[curx][cury] = timer;
   				timer += 1;
   			}
   		}
   		if(dir == 'S')
   		{
   			for(int i = 0;steps > i;i++)
   			{   				
   				cury -= 1;
   				if(field[curx][cury] != 0) ans = min(ans,timer - field[curx][cury]);
   				field[curx][cury] = timer;
   				timer += 1;
   			}
   		}
   		if(dir == 'E')
   		{
   			for(int i = 0;steps > i;i++)
   			{   				
   				curx += 1;
   				if(field[curx][cury] != 0) ans = min(ans,timer - field[curx][cury]);
   				field[curx][cury] = timer;
   				timer += 1;
   			}
   		}
   		if(dir == 'W')
   		{
   			for(int i = 0;steps > i;i++)
   			{   				
   				curx -= 1;
   				if(field[curx][cury] != 0) ans = min(ans,timer - field[curx][cury]);
   				field[curx][cury] = timer;
   				timer += 1;
   			}
   		}
   		//cout << curx - mxN << " " << cury - mxN << " " << ans << endl;
   	}
   	if(ans == INF)
   	cout << "-1" << endl;
   	else
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