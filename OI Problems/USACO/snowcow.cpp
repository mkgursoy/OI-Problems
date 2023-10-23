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

int mxn = 1e18;
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

// A very messy but correct range update range query fenwick tree
struct fenwicktree
{
private:int fft[100005],fft2[100005];
public:
	void init(vector<int> ar,int n)
	{
		memset(fft,0,sizeof(fft));
		memset(fft2,0,sizeof(fft2));
		
		for(int i=1;n>=i;i++) range_add(ar[i-1],i,i,n);
		
		


	}
	void print(int n)
	{
		for(int i = 1;n>=i;i++) cout << fft[i] << " ";
		cout << endl;
		for(int i = 1;n>=i;i++) cout << fft2[i] << " ";
			cout << endl;
	}
	int query(int l,int r)
	{
		int sumtotal = 0;
		int sumleft = 0;
		int i;
		for(i = r;i>0;i-=i&-i) sumtotal += fft[i];
			sumtotal *= r;
		
		for(i = r;i>0;i-=i&-i) sumtotal -= fft2[i];
		
		for(i = l-1;i>0;i-=i&-i) sumleft += fft[i];
			sumleft *= l-1;
		
		for(i = l-1;i>0;i-=i&-i) sumleft -= fft2[i];

		return sumtotal-sumleft;
		
		

		
	}
	void range_add(int value,int l,int r,int n)
	{
		add(fft,value,l,n);
		add(fft,-value,r+1,n);
		add(fft2,value*(l-1),l,n);
		add(fft2,-value*r,r+1,n);
	}
	void add(int* tree,int value,int place,int n)
	{

		for(int i=place;n>=i;i+=i&-i)
		{
			
			tree[i] += value;

		}
	}

};
int n;
vector<int> value;
int code[100005];
vector<int> subtree_length;
vector<int> adj[100005];
fenwicktree ft;
void upd(int val,int pos)
{
	ft.range_add(val,code[pos],code[pos] + subtree_length[code[pos]]-1,n);
}
void query(int pos)
{
	cout << ft.query(code[pos],code[pos] + subtree_length[code[pos]]-1) << endl;
}

void tree_progression(int pos,int parent)
{

	code[pos] = value.size();
	subtree_length.push_back(1);
	value.push_back(0);
	

	for(auto it : adj[pos])
	{
		if(it != parent)
		{
			tree_progression(it,pos);
			subtree_length[code[pos]] += subtree_length[code[it]];
		}
	}
}
void solve()
{
	freopen("snowcow.in","r",stdin);
	freopen("snowcow.out","w",stdout);
   	int q1;
   	cin >> n >> q1;

   	//constructing the adjacency matrix

   	for(int i = 0;n-1 > i;i++)
   	{

   		int x,y;
   		cin >> x >> y;
   		adj[x-1].push_back(y-1);
   		adj[y-1].push_back(x-1);
   	}
   	/*
		Tree Progression Just Like In CP Handbook:
		for sample :
		tree progression 1 2 3 4 5
		subtree size 	 5 1 3 1 1
		current value 	 0 0 0 0 0
   	*/
   	tree_progression(0,-1);
   
   	ft.init(value,n);

   	//Every relevant query done for each color k
  	priority_queue<int> pq[100005];

   	while(q1--)
   	{
   		
   		int op;
   		cin >> op;

   		if(op == 1)
   		{
   			int x,k;
   			cin >> x >> k;
   			// range updating the subtree
   			upd(1,x-1);
   			

   			queue<int> que;

   			while(pq[k-1].size())
   			{
   				if(code[pq[k-1].top()] > code[x-1]) break;
   				int piv = pq[k-1].top();
   				que.push(piv);

   				pq[k-1].pop();
   			}
   			//for each subtree colored in the color minus them because theyve already been colored
   			while(pq[k-1].size())
   			{
   				if(code[x-1] + subtree_length[code[x-1]]-1 < code[pq[k-1].top()]) break;

   				upd(-1,pq[k-1].top());
   				pq[k-1].pop();
   			}
   			//putting relevant queries back in
   			while(que.size())
   			{

   				pq[k-1].push(que.front());
   				que.pop();
   			}
   			//after removing all subtree queries add the node query to the priority queue
   			pq[k-1].push(x-1);


   			
   		}
   		if(op == 2)
   		{
   			int x;
   			cin >> x;
   			//output the range query of the sums in the subtree
   			query(x-1);

   		}
   	}

 	
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


