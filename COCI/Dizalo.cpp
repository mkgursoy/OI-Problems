#include<bits/stdc++.h>
#include<array>
using namespace std;
#define int long long
#define local_test freopen("/Users/metinkasim/Documents/in.txt","r",stdin);freopen("/Users/metinkasim/Documents/out.txt","w",stdout);
int32_t main()
{
	//local_test
	int n,q;
	cin >> n >> q;
	int a[n];
	int ind[n];
	vector<int> vec;
	for(int i = 0;n > i;i++) cin >> a[i] , ind[a[i]-1] = i;
	int ans = n;
	int mx = -1;
	for(int i = 0;n > i;i++)
	{
		if(ind[i] > mx)
		{
			mx = ind[i];
			for(int j = 0;ind[i] > j;j++)
			{
				if(a[j] > i) ans++;
			}
		}
	}
	int h = q;
	cout << ans << " ";
	map<int,int> mp;
	while(q--)
	{
		int rem;
		cin >> rem;
		mp[rem] += 1;
		ans = n-(h-q);
		mx = -1;
		for(int i = 0;n > i;i++)
		{
			if(mp[i+1]) continue;			
			if(ind[i] > mx)
			{
				mx = ind[i];
				for(int j = 0;ind[i] > j;j++)
				{
					if(mp[a[j]])
					{
						continue;
					}
					if(a[j] > i) ans++;
				}
			}
		}
		cout << ans << " ";
	}
	
	
}