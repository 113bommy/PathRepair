#include <bits/stdc++.h>
using namespace std;
unsigned long long n, a, t, i, kolvo0, kolvo1, j;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> a;
      if (a == 0) kolvo0++;
      if (a == 1) kolvo1++;
    }
    j = pow(2, kolvo0) * kolvo1;
    kolvo0 = 0;
    kolvo1 = 0;
    cout << j;
  }
}
