#include <iostream>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#include "vector"
#include "algorithm"

#include "numeric"
#include "limits"
#include "set"
#define ull unsigned long long
#define dd double
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define S second
#define F first
#define MP make_pair
#define el "\n"
#define PI 3.14159265
using namespace std;
ll M=1e9+7;
const int sz=1e5+10;
const int OO=0x3f3f3f3f;
#define all(my) my.begin(), my.end()
#define rall(my) my.rbegin(), my.rend()



// why did not i use tuple instead ? 
// Using a struct in this context is generally more readable and maintainable than using a tuple. A struct allows you to give
// meaningful names to the fields (e.g., x, y, r), which makes the code easier to understand. 
struct Radiator {
    int x, y, r;
};

bool isWarm(int gx, int gy, const vector<Radiator>& radiators) {
    for (const auto& radiator : radiators) {
        int dx = gx - radiator.x;
        int dy = gy - radiator.y;
        if (dx * dx + dy * dy <= radiator.r * radiator.r)
            return true;
    }
    return false;
}

int main() {
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    
    int n;
    cin >> n;
    
    vector<Radiator> radiators(n);
    for (int i = 0; i < n; ++i) {
        cin >> radiators[i].x >> radiators[i].y >> radiators[i].r;
    }

    int xmin = min(xa, xb);
    int xmax = max(xa, xb);
    int ymin = min(ya, yb);
    int ymax = max(ya, yb);

    int blanketCount = 0;

    for (int x = xmin; x <= xmax; ++x) {
        if (!isWarm(x, ymin, radiators)) blanketCount++;
        if (!isWarm(x, ymax, radiators)) blanketCount++;
    }
    
    for (int y = ymin + 1; y < ymax; ++y) {
        if (!isWarm(xmin, y, radiators)) blanketCount++;
        if (!isWarm(xmax, y, radiators)) blanketCount++;
    }

    cout << blanketCount << endl;

    return 0;
}
