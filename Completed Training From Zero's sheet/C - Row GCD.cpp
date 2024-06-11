#include <iostream>
#include <vector>
#include <numeric> 
using namespace std;
// the trick here is about this formula Gcd(a,b) == Gcd(a-b,b) 
// so we gotta use it here 
long long computeGCD(long long a, long long b) {
    return gcd(a, b);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    vector<long long> b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    long long commonGCD = 0;
    for (int i = 1; i < n; ++i) {
        commonGCD = computeGCD(commonGCD, a[i] - a[0]);
    }

    for (int j = 0; j < m; ++j) {
        long long result = computeGCD(commonGCD, a[0] + b[j]);
        cout << result << " ";
    }
    cout << endl;

    return 0;
}
