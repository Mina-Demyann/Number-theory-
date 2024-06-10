#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

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
