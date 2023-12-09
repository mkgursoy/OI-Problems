#include<bits/stdc++.h>
#include<array>
using namespace std;
#define int long long
#define local_test freopen("/Users/metinkasim/Documents/in.txt","r",stdin);freopen("/Users/metinkasim/Documents/out.txt","w",stdout);

const int mxN = 105;
int a[mxN][mxN][mxN];
int vis[mxN][mxN][mxN];
array<int,3> st;
array<int,3> en;
int n;
bool ch(int x,int y,int z)
{
	if(n > z && n > x && n > y && x >= 0 && y >= 0 && z >= 0 && !vis[z][x][y] && a[z][x][y] != 1)
	{
		vis[z][x][y] = 1;
		return true;
	} 
	else
	{
		return false;
	}
}
int32_t main()
{
	//local_test
	cin >> n;
	cin >> st[0] >> st[1] >> st[2];
	cin >> en[0] >> en[1] >> en[2];
	st[0]--,st[1]--,st[2]--,en[0]--,en[1]--,en[2]--;

	for(int i = 0;n > i;i++)
	{
		for(int j = 0;n > j;j++)
		{
			string s;
			cin >> s;
			for(int k = 0;n > k;k++)
			{
				a[i][j][k] = s[k] - '0';
			}
		}
	}

	queue<pair<array<int,3>,int>> bfs_que;
	bfs_que.push({st,0});
	while(bfs_que.size())
	{
		pair<array<int,3>,int> bfs;
		bfs = bfs_que.front();
		bfs_que.pop();
		if(bfs.first == en)
		{
			cout << bfs.second << " ";
			return 0;
		}
		if(ch(bfs.first[0]+1,bfs.first[1],bfs.first[2])) bfs_que.push({{bfs.first[0]+1,bfs.first[1],bfs.first[2]},bfs.second + 1});
		if(ch(bfs.first[0]-1,bfs.first[1],bfs.first[2])) bfs_que.push({{bfs.first[0]-1,bfs.first[1],bfs.first[2]},bfs.second + 1});
		if(ch(bfs.first[0],bfs.first[1]+1,bfs.first[2])) bfs_que.push({{bfs.first[0],bfs.first[1]+1,bfs.first[2]},bfs.second + 1});
		if(ch(bfs.first[0],bfs.first[1]-1,bfs.first[2])) bfs_que.push({{bfs.first[0],bfs.first[1]-1,bfs.first[2]},bfs.second + 1});
		if(ch(bfs.first[0],bfs.first[1],bfs.first[2]+1)) bfs_que.push({{bfs.first[0],bfs.first[1],bfs.first[2]+1},bfs.second + 1});
		if(ch(bfs.first[0],bfs.first[1],bfs.first[2]-1)) bfs_que.push({{bfs.first[0],bfs.first[1],bfs.first[2]-1},bfs.second + 1});
	}
	cout << "-1";
}