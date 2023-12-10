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
multiset<int> st;
const int mxN = 1e5 + 5;
int n,m;
vector<pair<ar<int,2>,ar<int,2>>> a;
int cur_toplam = 0;
void solve()
{
   cin >> n;
   for(int i = 0;n > i;i++)
   {
   		int x1,y1,x2,y2;
   		cin >> x1 >> y1 >> x2 >> y2;
   		if(x1 > x2) swap(x1,x2);
   		if(y1 > y2) swap(y1,y2);
   		ar<int,2> f = {x1, -1};
   		ar<int,2> s = {y1 , y2};
   		ar<int,2> f1 = {x2 , +1};
   		a.push_back(make_pair(f,s));
   		a.push_back(make_pair(f1,s));
   }
   sort(all(a));
   int prev = 0;
   int ans = 0;
   for(auto it : a)
   {
   	   	ans += (it.first[0] - prev) * cur_toplam;
   	   	cout << ans << " " << cur_toplam << endl;
   		prev = it.first[0];
   		if(it.first[1] == 1)
   		{
   			st.erase(st.find(it.second[0]));
   			st.erase(st.find(it.second[1]));
   			if(st.size())
   			{
   				auto r = st.upper_bound(it.second[1]);
   				if(r != st.begin()) r--;
   				auto l = st.upper_bound(it.second[0]);
   				int r_deger = *r;
   				int l_deger = 0;
   				if(l != st.end())
   				{
   					l_deger = *l;
   				}
   				cout << l_deger << " , " << r_deger << endl;
   				if(r_deger == l_deger)
   				{
   					auto r1 = st.upper_bound(it.second[1]);
   					auto l2 = st.upper_bound(it.second[0]);
   					if(l2 != st.begin() && r1 != st.end())
   					{
   						cur_toplam -= 0;
   					}
   					else if(l2 == st.begin())
   					{
   						cur_toplam -= l_deger - it.second[0];
   					}
   					else
   						cur_toplam -= it.second[1] - r_deger;
   				}
   				else if(l_deger > r_deger)
   				{
   					cur_toplam -= 0;
   				}
   				else
   				cur_toplam -= it.second[1] - r_deger + l_deger  - it.second[0];
   				
   			}
   			else
   				cur_toplam = 0;
   			
   		}
   		else
   		{
   			
   			if(st.size() == 0)
   			{
   				cur_toplam += it.second[1] - it.second[0];
   			}
   			else
   			{

   				auto r = st.upper_bound(it.second[1]);
   				if(r != st.begin()) r--;
   				auto l = st.upper_bound(it.second[0]);

   				int r_deger = *r;
   				int l_deger = 0;

   				if(l != st.end())
   				{
   					l_deger = *l;
   				}
   				cout << l_deger << " , " << r_deger << endl;
   				if(r_deger == l_deger)
   				{
   					auto r1 = st.upper_bound(it.second[1]);
   					auto l2 = st.upper_bound(it.second[0]);
   					if(l2 != st.begin() && r1 != st.end())
   					{
   						cur_toplam += 0;
   					}
   					else if(l2 == st.begin())
   					{
   						cur_toplam += l_deger - it.second[0];
   					}
   					else
   						cur_toplam += it.second[1] - r_deger;

   				}
   				else if(l_deger > r_deger)
   				{
   					cur_toplam += 0;
   				}
   				else
   				cur_toplam += r_deger - l_deger;
   			}
   			st.insert(it.second[0]);
   			st.insert(it.second[1]);
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