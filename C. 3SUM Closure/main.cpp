// When i wrote this code, only me and God knew how it works. Now only God knows...
// https://codeforces.com/problemset/problem/1698/C

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MAJOONI ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ONLINE_JUDGE
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
#define int long long
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> c_set;

void solve()
{
    int len, num;
    cin >> len;
    vector<int> pos, neg, zer, all;
    for (int i{}; i < len; ++i)
    {
        cin >> num;
        if (num > 0)
        {
            pos.push_back(num);
            all.push_back(num);
        }
        else if (num < 0)
        {
            neg.push_back(num);
            all.push_back(num);
        }
        else if (zer.size() < 2)
        {
            zer.push_back(num);
            all.push_back(num);
        }
    }

    if (pos.size() > 2 || neg.size() > 2)
        cout << "NO" << endl;
    else
    {
        bool res{true};
        int len = all.size();
        for (int i{}; i < len; ++i)
        {
            for (int j{i + 1}; j < len; ++j)
            {
                for (int k{j + 1}; k < len; ++k)
                {
                    bool flag{false};
                    for (int sum{}; sum < len; ++sum)
                    {
                        if (all[sum] == all[i] + all[j] + all[k])
                            flag = true;
                    }
                    res = flag;
                    if (!flag)
                    {
                        cout << "NO" << endl;
                        return;
                    }
                }
            }
        }
        cout << ((res) ? "YES" : "NO") << endl;
    }
}                        

    int32_t main()
    {
        MAJOONI
#ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
#endif
        int tc;
        cin >> tc;
        while (tc--)
            solve();
    }