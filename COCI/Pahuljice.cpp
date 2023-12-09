#include<bits/stdc++.h>
#include<array>
using namespace std;
#define int long long
#define local_test freopen("/Users/metinkasim/Documents/in.txt","r",stdin);freopen("/Users/metinkasim/Documents/out.txt","w",stdout);

const int mxN = 55,mxM = 55;
string a[mxN];
int n,m;
bool ch(int x,int y,char target)
{
	if(n > x && n > y && x >= 0 && y >= 0 && a[x][y] == target)
	{
		return true;
	} 
	else
	{
		return false;
	}
}
int inc(int i,int j,int x,int y,char target,int ans)
{
	if(ch(i+x,j+y,target)) return inc(i+x,j+y,x,y,target,ans + 1);
	else
		return ans;
}
int find(int i,int j)
{
	char special = 92;
	int a = inc(i,j,1,1,special,0);
	int b = inc(i,j,-1,-1,special,0);
	int c = inc(i,j,1,-1,'/',0);
	int d = inc(i,j,-1,1,'/',0);
	int e = inc(i,j,1,0,'|',0);
	int f = inc(i,j,-1,0,'|',0);
	int g = inc(i,j,0,1,'-',0);
	int h = inc(i,j,0,-1,'-',0);

	return min({a,b,c,d,e,f,g,h});

}
int32_t main()
{
	//local_test
	cin >> n >> m;
	for(int i = 0;n > i;i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 0;n > i;i++)
	{
		for(int j = 0;m > j;j++)
		{
			if(a[i][j] == '+')
			{
				ans = max(ans,find(i,j));
			}
		}
	}
	cout << ans << endl;
	
}