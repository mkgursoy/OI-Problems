/*
    Author:Matkap(prefixsumenjoyer23)
    
*/
#include <bits/stdc++.h>

using namespace std;
#define fr freopen("/Users/metinkasim/Documents/in.txt","r",stdin);freopen("/Users/metinkasim/Documents/out.txt","w",stdout);


#define int long long
#define endl "\n"

#define all(x) x.begin(),x.end()

int mxn = 1e16;
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

struct SegT
{
    vector<int> tree_sum,lazy_sum; //For Summation Tree
    vector<int> tree_min,lazy_min; //For Minimum Tree
    
    void Init(int n,int* ar)
    {
        
        lazy_min.resize(3*n+5);
        lazy_sum.resize(3*n+5);
        tree_min.resize(3*n+5);
        fill(all(tree_min),mxn);
        tree_sum.resize(3*n+5);

        Create_Tree(n,ar,1,n,1);
    }
    void Update(int n,int l,int r,int value)
    {
        
        Update_Tree(1,n,l,r,1,value);
    }
    void MinQuery(int n,int l,int r)
    {
        
        int ans = Min_Query_Tree(1,n,l,r,1);
        cout << ans << endl;
    }
    void SumQuery(int n,int l,int r)
    {
        

        int ans = Sum_Query_Tree(1,n,l,r,1);
        cout << ans << endl;
    }

    void Create_Tree(int n,int* ar,int l,int r,int pos)
    {
        if(l == r)
        {
            tree_sum[pos] = ar[l-1];
            tree_min[pos] = ar[l-1];
            return;
        }

        int mid = (l+r)/2;

        Create_Tree(n,ar,l,mid,pos*2);
        Create_Tree(n,ar,mid+1,r,pos*2+1);

        tree_sum[pos] = tree_sum[pos*2] + tree_sum[pos*2+1];
        tree_min[pos] = min(tree_min[pos*2],tree_min[pos*2+1]);
    }
    void Update_Tree(int l,int r,int tl,int tr,int pos,int value)
    {
        if(lazy_min[pos] != 0)
        {
            tree_min[pos] += lazy_min[pos];
            

            if(l != r)
            {
                lazy_min[pos*2] += lazy_min[pos];
                lazy_min[pos*2+1] += lazy_min[pos];
            }

            lazy_min[pos] = 0;
        }

        if(lazy_sum[pos] != 0)
        {
            tree_sum[pos] += lazy_sum[pos] * (r-l+1);
            

            if(l != r)
            {
                lazy_sum[pos*2] += lazy_sum[pos];
                lazy_sum[pos*2+1] += lazy_sum[pos];
            }

            lazy_sum[pos] = 0;
        }

        if(tl > r || tr < l || r < l) return;

        if(tl <= l && tr >= r)
        {
            tree_sum[pos] += value * (r-l+1);
            tree_min[pos] += value;

            if(l != r)
            {
                lazy_min[pos*2] += value;
                lazy_min[pos*2+1] += value;

                lazy_sum[pos*2] += value;
                lazy_sum[pos*2+1] += value;
            }
            return;
        }

        int mid = (l+r)/2;

        Update_Tree(l,mid,tl,tr,pos*2,value);
        Update_Tree(mid+1,r,tl,tr,pos*2+1,value);

        tree_min[pos] = min(tree_min[pos*2],tree_min[pos*2+1]);
        tree_sum[pos] = tree_sum[pos*2] + tree_sum[pos*2+1];
    }
    int Min_Query_Tree(int l,int r,int tl,int tr,int pos)
    {
        if(lazy_min[pos] != 0)
        {
            tree_min[pos] += lazy_min[pos];
            

            if(l != r)
            {
                lazy_min[pos*2] += lazy_min[pos];
                lazy_min[pos*2+1] += lazy_min[pos];
            }
            lazy_min[pos] = 0;

            if(l != r)
            {
                tree_min[pos] = min(tree_min[pos*2] + lazy_min[pos*2],tree_min[pos*2+1] + lazy_min[pos*2+1]);

            }
        }
        
        if(tl > r || tr < l || r < l) return mxn;

        if(tl <= l && tr >= r)
        {
            return tree_min[pos];
        }

        int mid = (l+r)/2;


        return min(Min_Query_Tree(l,mid,tl,tr,pos*2) , Min_Query_Tree(mid+1,r,tl,tr,pos*2+1));
    }
    int Sum_Query_Tree(int l,int r,int tl,int tr,int pos)
    {

        if(lazy_sum[pos] != 0)
        {
            tree_sum[pos] += lazy_sum[pos] * (r-l+1);
           

            if(l != r)
            {
                lazy_sum[pos*2] += lazy_sum[pos];
                lazy_sum[pos*2+1] += lazy_sum[pos];
            }
            lazy_sum[pos] = 0;
        }

        if(tl > r || tr < l || r < l) return 0;

        if(tl <= l && tr >= r)
        {
            return tree_sum[pos];
        }

        int mid = (l+r)/2;


        return Sum_Query_Tree(l,mid,tl,tr,pos*2) + Sum_Query_Tree(mid+1,r,tl,tr,pos*2+1);
    }

};
void solve()
{
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    int n,q;
    cin >> n >> q;
    

    int ar[n];
    SegT st;

    for(int i = 0;n > i;i++)
    {
        cin >> ar[i];
    }

    st.Init(n,ar);

    while(q--)
    {
        char op;
        cin >> op;
        if(op == 'M')
        {
            int x,y;
            cin >> x >> y;

            st.MinQuery(n,x,y);
        }
        if(op == 'S')
        {
            int x,y;
            cin >> x >> y;

            st.SumQuery(n,x,y);
        }
        if(op == 'P')
        {
            int x,y,z;
            cin >> x >> y >> z;
            st.Update(n,x,y,z);
        }
    }
}



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  //  fr

    int t;
    t=1;
   // cin >> t;
    while(t--) solve();

}


