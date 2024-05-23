// When i wrote this code, only me and God knew how it works. Now only God knows...
// NO LINK

#include <bits/stdc++.h>
#define MAJOONI ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ONLINE_JUDGE
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
#define endl '\n'
#define int long long
using namespace std;

struct segmenttree
{
    vector<int> st;
    int n;
    void init(int _n)
    {
        n = _n;
        st.clear();
        st.resize(4 * _n);
    }
    void build(int l, int r, int node, int a[])
    {
        if (l == r)
        {
            st[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, node * 2 + 1, a);
        build(mid + 1, r, node * 2 + 2, a);
        st[node] = min(st[2 * node + 1], st[2 * node + 2]);
    }
    void update(int l, int r, int indup, int val, int node)
    {
        if (l == r)
        {
            st[node] = val;
            return;
        }
        else
        {
            int mid = (l + r) / 2;
            if (indup >= l && indup <= mid)
            {
                update(l, mid, indup, val, node * 2 + 1);
            }
            else
            {
                update(mid + 1, r, indup, val, node * 2 + 2);
            }
            st[node] = min(st[2 * node + 1], st[2 * node + 2]);
        }
    }
    int query(int si, int se, int l, int r, int node)
    {
        if (se < l || si > r || l > r)
        {
            return INT_MAX;
        }
        if (si >= l && se <= r)
        {
            return st[node];
        }
        int mid = (si + se) / 2;
        int q1 = query(si, mid, l, r, node * 2 + 1);
        int q2 = query(mid + 1, se, l, r, node * 2 + 2);
        return min(q1, q2);
    }
    void build(int n, int a[])
    {
        init(n);
        build(0, n - 1, 0, a);
    }
    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }
    void update(int index, int val)
    {
        update(0, n - 1, index, val, 0);
    }
};

struct fenwick
{
    vector<int> fn;
    int n;
    fenwick() {}
    fenwick(int n)
    {
        init(n);
    }
    void init(int _n)
    {
        n = _n + 10;
        fn.clear();
        fn.resize(n, 1e18);
    }
    void update(int x, int val)
    {
        x++;
        while (x < n)
        {
            fn[x] = min(fn[x], val);
            x += (x & (-x));
        }
    }
    int query(int x)
    {
        x++;
        int ans = INT_MAX;
        while (x)
        {
            ans = min(ans, fn[x]);
            x -= (x & (-x));
        }
        return ans;
    }
};

class Graph
{
    list<int> *l;
    int len;

public:
    Graph(int n)
    {
        this->len = n;
        l = new list<int>[len];
    }
    void addEdge(int i, int j, int undirected = true)
    {
        l[i].push_back(j);
        if (undirected)
            l[j].push_back(i);
    }
};

void solve()
{
    string s ; 
    cin >> s ; 
    int len = s.size() , f = 0 ;
    char start ;  
    map<char , int> c ; 
    for(int i = 0 ; i < len ; i++) c[s[i]]++ ;

    for(auto l : c){
        if(l.first != s[0]){
            cout << "YES\n" ; 
            cout << l.first ;
            f = 1 ; 
            start = l.first ; 
            break ;
        }
    }
    if(f == 0){
        cout << "NO\n" ; 
        return ;
    }

    for(auto l : c){
        int g = l.second ; 
        if(l.first == start) g-- ; 
        for(int i = 0 ; i < g ; i++) cout << l.first ;
    }
    cout << endl ; 
}

int32_t main()
{
    MAJOONI
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int tc ; cin >> tc ; while(tc--)
    solve();
}