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

int INF = 1e16;

void setIO(string name = "") 
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
const int mxN = 1e5;
ar<int,3> dik[mxN];
ar<int,3> sark[mxN];
int h,n,m;
bool checkVertical(ar<int,3> a,ar<int,3> b)
{
	return (a[0] >= b[0] && !(a[0] > b[1])) || (b[0] >= a[0] && !(b[0] > a[1]));
}
bool compareHorizontal(ar<int,3> a,ar<int,3> b)
{
	return a[2] >= b[2];
}
bool compareHorizontal2(ar<int,3> a,ar<int,3> b)
{
	return a[2] <= b[2];
}
void solveVertical()
{
	int ans = h;
	int lb = 0,rb = 0;
	sort(dik , dik + n);
	sort(sark , sark + m);
	for(int i = 0;n > i;i++)
	{
		ans = min(ans , h - dik[i][2]);
	}
	while(n > lb && m > rb)
	{
		if(checkVertical(dik[lb] , sark[rb]))
		{
			ans = min(ans , (h - dik[lb][2]) - sark[rb][2]);
			rb += 1;
		}
		else if(dik[lb][0] > sark[rb][1]) rb += 1;
		else
			lb += 1;
	}
	cout << ans << " ";
}
void solveHorizontal()
{
	int ans = INF;
	sort(dik , dik + n , compareHorizontal2);
	sort(sark , sark + m , compareHorizontal);
	int lb = 0, rb = 0;
	set<int> ms;
	while(n > lb && m > rb)
	{
		while(m > rb && sark[rb][2] + dik[lb][2] >= h)
		{
			ms.insert(sark[rb][1]);
			ms.insert(sark[rb][0]);
			rb += 1;
		}
		if(ms.lower_bound(dik[lb][1]) != ms.end())
		ans = min(ans , *(ms.lower_bound(dik[lb][1])) - dik[lb][1]);
		if(ms.upper_bound(dik[lb][0]) != ms.begin())
		ans = min(ans , dik[lb][0] - *(--ms.upper_bound(dik[lb][0])));
		lb += 1;
	}
	if(ans == INF)
	{
		cout << "-1" << endl;
	}
	else
	cout << ans << endl;
}
void solve()
{
   	cin >> h >> n >> m;
   	for(int i = 0;n > i;i++)
   	{
   		cin >> dik[i][0] >> dik[i][1] >> dik[i][2];
   	}	
   	for(int i = 0;m > i;i++)
   	{
   		cin >> sark[i][0] >> sark[i][1] >> sark[i][2];
   	}
   	solveVertical();
   	solveHorizontal();
}



int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	//fr

	int t;
	t=1;
	cin >> t;
	while(t--) solve();

}