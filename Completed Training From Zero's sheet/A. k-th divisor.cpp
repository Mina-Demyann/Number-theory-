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


// do not forget ot add in Github
int maxPower(int n, int p) {
    int x = 0;
    for (int i = p; i <= n; i *= p) {
        x += n / i;
    }
    return x;
}


vector<bool> sieve() {
    int n = 1e6;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p*p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p*p; i <= n; i += p)
                is_prime[i] = false;
        }
    }

    return is_prime;
}
ll mul(ll a,ll b,ll m)
{
    return ((a%m)*(b%m))%m;
}
ll binaryExponentiation(ll x,ll n)
{
    ll result=1;
    while(n>0)
    {
        if(n%2==1){result=result*x;}
        x=x*x;
        n=n/2;
    }
    return result;
}

ll modularExponentiation(ll x,ll n,ll m)
{
    ll result=1;
    while(n>0)
    {
        if(n%2==1){result=mul(result,x,m);}
        x=mul(x,x,m);
        n=n/2;
    }
    return result;
}
void solve()
{
    ll n , k ; cin >> n >> k ;
    set<ll> div;
    for (ll i = 1; i*i<= n; ++i) {
        if(n%i==0) {
            div.insert(i);
            if (i*i!=n)
            { div.insert(n / i); }
        }
    }

    if (k-1 < div.size()) {
        auto it = div.begin();
        std::advance(it, k-1);
        cout << *it << el;
    } else {
        cout << -1 << el;
    }
}

 int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t{1};
    //cin >> t;

    while (t--) {
      solve();


     return 0;
}
