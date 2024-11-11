#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> arr(n);
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (n % 2 == 0) {
    cout << "YES" << endl;
  } else {
    bool flag = false;
    for (long long int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        flag = true;
        break;
      }
    }
    if (flag == true) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
