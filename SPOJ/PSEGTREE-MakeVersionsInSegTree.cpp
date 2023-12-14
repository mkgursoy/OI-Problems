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
struct node
{
	int val;
	node *left,*right;
	node() {}
	node(node* _left,node* _right,int _val)
	{
		left = _left;
		right = _right;
		val = _val;
	}

};
const int mxN = 1e5 + 7;
int a[mxN];
node* ver[mxN];
int n,q;
void build(node* cur,int l,int r)
{
	if(l == r)
	{
		cur->val += a[l];
		return;
	}
	int mid = (l+r)/2;
	cur->right = new node(NULL,NULL,0);
	cur->left = new node(NULL,NULL,0);
	build(cur->right,mid+1,r);
	build(cur->left,l,mid);
	cur->val = cur->left->val + cur->right->val;
}
void update(node* prev,node* cur,int l,int r,int idx,int value)
{
	if(l > r || l > idx || idx > r) return;
	if(l == r)
	{
		cur->val += prev->val + value;
		return;
	}
	int mid = (l+r)/2;
	if(idx > mid)
	{
		cur->left = prev->left;
		cur->right = new node(NULL,NULL,0);
		update(prev->right,cur->right,mid+1,r,idx,value);
	}
	else
	{
		cur->right = prev->right;
		cur->left = new node(NULL,NULL,0);
		update(prev->left,cur->left,l,mid,idx,value);
	}

	cur->val = cur->left->val + cur->right->val;
}
int query(node* cur,int l,int r,int tl,int tr)
{
	if(l > r || l > tr || tl > r) return 0;
	if(tl <= l && l <= r && r <= tr) return cur->val;
	int mid = (l+r)/2;
	return query(cur->right,mid+1,r,tl,tr) + query(cur->left,l,mid,tl,tr);
}
void solve()
{
	cin >> n;
   	for(int i = 0;n > i;i++) cin >> a[i];
   	node* root = new node(NULL,NULL,0);
   	build(root,0,n-1);
   	ver[0] = root;
   	int xd = 0;
   	cin >> q;
   	while(q-->0)
   	{
   		int type;
   		cin >> type;
   		if(type == 1)
   		{
   			int b,c,d;
   			cin >> b >> c >> d;
   			ver[++xd] = new node(NULL,NULL,0);
   			update(ver[b],ver[xd],0, n-1 , c-1,d);
   		}
   		if(type == 2)
   		{
   			int a,l,r;
   			cin >> a >> l >> r;
   			if(l > r) swap(l,r);
   			cout << query(ver[a] , 0 , n-1 ,l-1 , r-1) << endl;
   		}
   	}
}



int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//	fr

	int t;
	t=1;
	//cin >> t;
	while(t--) solve();

}