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
#define setIO(s) freopen(s".in")
int INF = 1e18;

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
const int mxN = 210 , mxM = 210;
string grid[mxN];
int pre_sum_horizontal[mxN][mxM];
int pre_sum_vertical[mxM][mxN];
int ans = 0;
void Calc(int i,int j,int i1,int j1)
{
	int horizontal = -1;
   	int vertical = -1;

   	if(pre_sum_horizontal[i][j1] - pre_sum_horizontal[i][j] == 0)
   	{
   		horizontal = j1 - j + 1;
   	}
   	if(pre_sum_vertical[j1][i] - pre_sum_vertical[j][i1] == 0)
   	{
   		vertical = i1 - i + 1;
   	}

   	if(vertical != -1 && horizontal != -1)
   	{
   		int ans1 = ans;
   		ans = max(ans,vertical * horizontal);
   		if(ans1 != ans)
   		cout << "POINT:" << endl << i << " " << j << endl << i1 << " " << j1 << endl;
   		
   	} 
}
void solve()
{
	//freopen("fortmoo.in","r",stdin);freopen("fortmoo.out","w",stdout);
   	int n,m;
   	cin >> n >> m;
   	for(int i = 0;n > i;i++)
   	{
   		cin >> grid[i];
   	}
   	for(int i = 0;n > i;i++)
   	{
   		for(int j = 0;m > j;j++)
   		{
   			if(j > 0)
   			pre_sum_horizontal[i][j] = pre_sum_horizontal[i][j-1];
   			pre_sum_horizontal[i][j] += (grid[i][j] == 'X');
   		}
   	}
   	for(int j = 0;m > j;j++)
   	{
   		for(int i = 0;n > i;i++)
   		{
   			if(i > 0)
   			pre_sum_vertical[j][i] = pre_sum_vertical[j][i-1];
   			pre_sum_vertical[j][i] += (grid[i][j] == 'X');
   		}
   	}
   	for(int i = 0;n > i;i++)
   	{
   		for(int j = 0;m > j;j++)
   		{
   			if(grid[i][j] == 'X') continue;
   			ar<int,2> first_point = {i,j};
   			while(i >= 0 && grid[i][j] == '.')
   			{
   				i -= 1;
   			}
   			i += 1;
   			ar<int,2> top_left = {i,j};
   			i = first_point[0];   
   			while(m-1 >= j && grid[i][j] == '.')
   			{ 				
   				Calc(top_left[0] , top_left[1] , i , j);
   				j += 1;
   			}
   			j = first_point[1];
   		}
   	}
   	cout << ans << endl;
}



int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	fr

	int t;
	t=1;
	//cin >> t;
	while(t--) solve();

}