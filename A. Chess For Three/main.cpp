// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://codeforces.com/problemset/problem/1973/A

#include <bits/stdc++.h>
#define MAJOONI ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ONLINE_JUDGE
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
#define endl '\n'
#define int long long
using namespace std;

void solve()
{
    int co = 0 ; 
    int a[3] ;  
    cin >> a[0] >> a[1] >> a[2] ; 
    sort(a , a + 3) ;
    while(true){
        if(a[1]) a[2]-- , a[1]-- , co++ ; 
        else break;
        sort(a , a + 3) ;
    }
    if(a[2] % 2 == 1) cout << -1 ; 
    else cout << co ;
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