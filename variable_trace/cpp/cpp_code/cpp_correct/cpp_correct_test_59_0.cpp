#include <bits/stdc++.h>
using namespace std;
void sol() {
  long long n;
  cin >> n;
  long long a[n][5];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      long long int cnt1 = 0, cnt2 = 0, cnt = 0;
      for (int l = 0; l < n; l++) {
        if (a[l][i] == 1) cnt++;
        if (a[l][j] == 1) cnt1++;
        if (a[l][i] == 1 && a[l][j] == 1) {
          cnt2++;
          cnt1--;
          cnt--;
        }
      }
      if (cnt <= n / 2 && cnt1 <= n / 2) {
        if (cnt + cnt1 + cnt2 == n) {
          cout << "YES"
               << "\n";
          return;
        }
      }
    }
  }
  cout << "NO"
       << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) sol();
  return 0;
}
