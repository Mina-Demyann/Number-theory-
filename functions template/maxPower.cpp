
#include <bits/stdc++.h>
int maxPower(int n, int p) {
    int x = 0;
    for (int i = p; i <= n; i *= p) {
        x += n / i;
    }
    return x;
}
void main()
{
  int n , p ; cin >> n >> p ; 
  maxPower(n,p); 
}
