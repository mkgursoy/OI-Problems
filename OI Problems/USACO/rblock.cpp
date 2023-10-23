/*
    Author:Matkap(prefixsumenjoyer23)
    
*/

#include <bits/stdc++.h>

using namespace std;
#define fr freopen("/Users/metinkasim/Documents/in.txt","r",stdin);freopen("/Users/metinkasim/Documents/out.txt","w",stdout);


#define int long long
#define endl "\n"
#define mod  998244353
#define all(x) x.begin(),x.end()

int mxn = 1e10;
int mnn = -mxn;

void outarr(int ans[],int n)
{
	for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
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
int gcd(int a, int b)
{

    if(b == 0) {
            return a;
    }
    else {
        return gcd(b, a % b);
    }
}
int lcm(int a,int b)
{
	return (a*b)/gcd(a,b);
}

void solve()
{
	freopen("rblock.in","r",stdin);
	freopen("rblock.out","w",stdout);
   	int n,m;
   	cin >> n >> m;
   	vector<pair<int,int>> adj[n];

   	for(int i = 0;m > i;i++)
   	{
   		int x,y,z;
   		cin >> x >> y >> z;

   		adj[x-1].push_back({y-1,z});
   		adj[y-1].push_back({x-1,z});

   	}
  	int dist[n];
  	int prev[n];


  	for(int i = 0;n > i;i++) dist[i] = mxn,prev[i] = 0;

  	priority_queue<pair<int,int>> pq;

  	pq.push({0,0});
  	dist[0] = 0;
  	
  	prev[0] = -1;

  	while(pq.size())
  	{
  		pair<int,int> piv;
  		piv = pq.top();
  		pq.pop();

  		

  		for(auto it : adj[piv.second])
  		{
  			if(dist[it.first] > it.second + piv.first)
  			{
  				dist[it.first] = it.second + piv.first;
  				pq.push({it.second + piv.first,it.first});
  				prev[it.first] = piv.second;
  				
  			}
  		}	
  	}
  	int mx1 = dist[n-1];
  	int mx = dist[n-1];

  	for(int i = n-1;i > 0;i = prev[i])
  	{	
  		for(int j = 0;adj[i].size() > j;j++)
  		{
  			if(adj[i][j].first == prev[i]) adj[i][j].second *= 2;
  		}
  		for(int j = 0;adj[prev[i]].size() > j;j++)
  		{
  			if(adj[prev[i]][j].first == i) adj[prev[i]][j].second *= 2;
  		}
  		for(int j = 0;n > j;j++) dist[j] = mxn;
  		
  		pq.push({0,0});
  	dist[0] = 0;
  	
  	

  	while(pq.size())
  	{
  		pair<int,int> piv;
  		piv = pq.top();
  		pq.pop();
  		for(auto it : adj[piv.second])
  		{
  			if(dist[it.first] > it.second + piv.first)
  			{
  				dist[it.first] = it.second + piv.first;
  				pq.push({it.second + piv.first,it.first});
  				
  			}
  		}	
  	}
  	mx = max(dist[n-1],mx);

  		for(int j = 0;adj[i].size() > j;j++)
  		{
  			if(adj[i][j].first == prev[i]) adj[i][j].second /=2;
  		}
  		for(int j = 0;adj[prev[i]].size() > j;j++)
  		{
  			if(adj[prev[i]][j].first == i) adj[prev[i]][j].second /= 2;
  		}
  	}

  	cout << mx - mx1 << endl;


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


