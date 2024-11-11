#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int a[n];
    int itr, maxa = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] >= maxa) {
        maxa = a[i];
        itr = i;
      }
    }
    int br = 0, maxbr = a[n - 1];
    for (int i = n - 1; i > itr; i--) {
      if (maxbr <= a[i]) br++;
      maxbr = max(a[i], maxbr);
    }
    cout << br << "\n";
  }
  return 0;
}
