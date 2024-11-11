#include <bits/stdc++.h>
using namespace std;
long long b[100];
int32_t main() {
  long long n;
  cin >> n;
  long long a[n + 1];
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= 7; j++) cin >> b[j];
    cout << b[1] << " " << b[2] << " " << b[7] - b[1] - b[2] << endl;
  }
}
