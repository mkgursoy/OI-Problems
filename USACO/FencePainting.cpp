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

void setIO(string name = "paint") 
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
void solve()
{
	setIO();
   	ar<int,2> p1 , p2;
   	cin >> p1[0] >> p1[1] >> p2[0] >> p2[1];
   	/*
   		Case 1:
   		_______
   		  ___  
   	*/
   	if((p1[0] <= p2[0] && p1[1] >= p2[1]) || (p1[0] >= p2[0] && p1[1] <= p2[1]))
   	{
   		cout << max(p1[1] , p2[1]) - min(p1[0] , p2[0]);
   		return;
   	}
   	/*
   		Case 2:
   		____ ____
   	*/
   	if((p1[0] > p2[1]) || p2[0] > p1[1])
   	{
   		cout << p1[1] + p2[1] - p1[0] - p2[0];
   		return;
   	}
   	/*
   		Case 3:
   		____
   		  ____
   	*/

   if(p1 > p2) swap(p1 , p2);

   cout << p2[1] - p1[0];
   	
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