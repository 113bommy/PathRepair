#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  long long c = floor(n / 2);
  for (int i = 1; i <= c; i++) {
    cout << arr[i] << " " << arr[0] << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
