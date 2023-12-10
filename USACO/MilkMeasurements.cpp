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

void setIO(string name = "measurement") 
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
bool comp(pair<ar<int,2>,string> a,pair<ar<int,2>,string> b)
{
	return a.first[0] < b.first[0];
}
void solve()
{
	//setIO();
	int n;
	cin >> n;
	int mx_cnt = n;
   	map<string,int> mp;
   	multiset<int> ms;
   	map<int,int> mx_cnt_vals;
   	mx_cnt_vals[0] = n;
   	int mx = 0;
   	int cnt = 0;
   	pair<ar<int,2>,string> a[n];
   	for(int i = 0;n > i;i++)
   	{
   		string x;
   		cin >> a[i].first[0] >> a[i].second >> x;
   		a[i].first[1] = x[1] - '0';
   		if(x[0] == '-') a[i].first[1] *= -1;
   		ms.insert(0);

   	}
   	sort(a,a + n,comp);
   	for(int i = 0;n > i;i++)
   	{
   		//cout << a[i].second << " " << a[i].first[1] << endl;
   		ms.erase(ms.find(mp[a[i].second]));
   		int old = mp[a[i].second];
   		mp[a[i].second] += a[i].first[1];

   		if(old == mx && mp[a[i].second] > mx)
   		{
   			if(mx_cnt > 1) cnt += 1;
   			mx_cnt = 1;
   			mx = mp[a[i].second];
   		//	cout << "OP1: " << a[i].second << endl;
   		}
   		else if(old == mx && mp[a[i].second] < mx)
   		{
   			mx_cnt -= 1;
   			cnt += 1;
   			if(mx_cnt == 0)
   			{
   				mx = *(--ms.end());
   				mx_cnt = mx_cnt_vals[mx];
   			}  			
   		//	cout << "OP2: " << a[i].second << endl;
   		}
   		else if(old < mx && mp[a[i].second] == mx)
   		{
   			mx_cnt += 1;
   			cnt += 1;
   		//	cout << "OP3: " << a[i].second << endl;
   		}
   		else if(old < mx && mp[a[i].second] > mx)
   		{
   			mx_cnt = 1;
   			cnt += 1;
   			mx = mp[a[i].second];
   		//	cout << "OP4: " << a[i].second << endl;
   		}
   		ms.insert(mp[a[i].second]);
   		//cout << mx_cnt << endl;
   		mx_cnt_vals[mx] = mx_cnt;
   	}
   	cout << cnt << endl;
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