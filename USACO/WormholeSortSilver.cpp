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

void setIO(string name = "wormsort") 
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
const int mxN = 1e5 + 7;
int elem[mxN];
int hole_length[mxN];
ar<int,2> hole[mxN];
int n,m;
void dfs(int pos,vector<int>* adj,int* visited,map<int,int>& comp,int cur_comp)
{
	visited[pos] = 1;
	//cout << pos << " - " << cur_comp << endl;
	comp[pos] = cur_comp;
	for(auto it : adj[pos])
	{
		if(!visited[it]) 
		{
			dfs(it,adj,visited,comp,cur_comp);
			
		}
	}

}
bool check(int pos)
{
	vector<int> adj[n+1];
	int vis[n+1];
	map<int,int> comp;
	int cur_comp = 0;
	memset(vis,0,sizeof(vis));
	for(int i = 1;n >= i;i++)
	{
		comp[i] = -1;
	}
	for(int i = 0;m > i;i++)
	{
		if(hole_length[i] >= pos) adj[hole[i][0]].push_back(hole[i][1]) , adj[hole[i][1]].push_back(hole[i][0]);
	}
	for(int i = 1;n >= i;i++)
	{
		if(!vis[i]) cur_comp += 1,dfs(i,adj,vis,comp,cur_comp);
	}
	for(int i = 1;n >= i;i++)
	{
		if(comp[i] != comp[elem[i-1]])
		{
			return false;
		}
		if(i != elem[i-1] && (comp[i] == -1 || comp[elem[i-1]] == -1))
		{
			//cout << i << " , " << comp[i] << endl;
			return false;
		}
	}
	return true;
}
void solve()
{
	setIO();
   	cin >> n >> m;
   	int ans = INF;
   	for(int i = 0;n > i;i++)
   	{
   		cin >> elem[i];
   	}
   	ar<int,3> temp[m];
   	for(int i = 0;m > i;i++)
   	{
   		cin >> temp[i][1] >> temp[i][2] >> temp[i][0];
   	}
   	sort(temp , temp + m);
   	for(int i = 0;m > i;i++)
   	{
   		hole[i] = {temp[i][1] , temp[i][2]};
   		hole_length[i] = temp[i][0];
   	}
   	int l = 0 , r = m-1;
   	if(is_sorted(elem , elem + n))
   	{
   		cout << "-1" << endl;
   		return;
   	}
   	while(r > l)
   	{
   		//cout << l << " " << r << endl;
   		int mid = (l + r) / 2;
   		if(check(hole_length[mid]))
   		{
   			l = mid+1;
   		}
   		else
   			r = mid;
   	}
   	if(check(hole_length[l]))
   		cout << hole_length[l] << endl;
   	else
   		cout << hole_length[l-1];

   	
}	



int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	//fr

	int t;
	t=1;
//	cin >> t;
	while(t--) solve();

}