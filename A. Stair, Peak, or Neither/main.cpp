// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://codeforces.com/problemset/problem/1950/A

#include<bits/stdc++.h>
#define MAJOONI ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
#define ONLINE_JUDGE
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
#define endl '\n'
typedef long long ll ;
using namespace std ;
vector<ll> mem ;

void solve(){
    int a , b , c ; cin >> a >> b >> c ; 
    if(a < b && b < c) cout << "STAIR\n" ; 
    else if(a < b && b > c) cout << "PEAK\n" ; 
    else cout << "NONE\n" ;
}

int main(){
    MAJOONI
    #ifndef ONLINE_JUDGE
    freopen("../input.txt" , "r" , stdin) ;
    freopen("../output.txt" , "w" , stdout) ;
    #endif
    int tc ; cin >> tc ; while(tc--)
    solve() ;
}