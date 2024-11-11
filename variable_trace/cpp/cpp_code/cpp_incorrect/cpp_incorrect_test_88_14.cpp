#include <bits/stdc++.h>
using namespace std;
bool arraySortedOrNot(long long int arr[], long long int n) {
  if (n == 0 || n == 1) return true;
  for (int i = 1; i < n; i++)
    if (arr[i - 1] > arr[i]) return false;
  return true;
}
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n % 2 == 0) {
    cout << "YES";
  } else {
    if (arraySortedOrNot(a, n)) {
      cout << "NO";
    } else {
      cout << "YES";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
