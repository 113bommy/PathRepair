#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, cnt = 0;
  cin >> n;
  int arr[n];
  for (int(i) = (0); (i) < (n); ++(i)) {
    cin >> arr[i];
  }
  long long x = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] > x) {
      cnt++;
      x = arr[i];
    }
    if (i == 0) {
      cout << cnt;
      return;
    }
  }
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
