#include <bits/stdc++.h>
using namespace std ;
#include <iostream>

#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <bitset>
#include <map>

#include <deque>
#include <string>

#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>

#include <ctime>
#include <cmath>
#define rep(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)

#define per(i,a,b) for(ll i=(ll)(a);i>(ll)(b);i--)
#define each(a, x) for (auto &a : x)
#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())
#include <numeric>
#include "string"
#define rall(my) my.rbegin(), my.rend()
#define ll long long
#define el "\n"
#define ull unsigned long long
#define dd double
#define ld long double
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


// do not forget to add it  on  Github
int maxPower(int n, int p) {
    int x = 0;
    for (int i = p; i <= n; i *= p) {
        x += n / i;
    }
    return x;
}
void solve()
{
    int n , m ; cin >> n >> m ;
    vector<int> deg(n+1 , 0 ) ;
    vector<vector<int>> rel(n+1) ;

    while (m--)
    {
        int a , b ; cin >> a >> b ;
        rel[a].pb(b) ; // 1 == 2
        // 2 == 1 , 3
        rel[b].pb(a);

        deg[a]++, deg[b]++ ;
    }
//    6 3
//    1 2
//    2 3
//    3 4
int grp{};
    while(1) // if there is nothing to remove
    {
        vector<int> rmv;// 1 , 4

        for (int i = 1; i <= n ; ++i) {
            if(deg[i] == 1)
                rmv.push_back(i) ;
        }

        if (rmv.empty()) { break; }

        grp++ ;

        for (auto s : rmv )// 1 , 4
        {
            deg[s] = 0 ;
            for (auto ne : rel[s]) { // 1 .. 2 , 5 ,6 /// 4 // 3
               if(deg[ne] > 0 ) {
                   deg[ne]--;
               }

            }

        }

    }
    cout << grp << el ;


}

 int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t{1};
    //cin >> t;

    while (t--) {
      solve();

//       cout << (a * (1 -std::pow(a,n)))/(1-a) << el ;
    }

    return 0;
}
