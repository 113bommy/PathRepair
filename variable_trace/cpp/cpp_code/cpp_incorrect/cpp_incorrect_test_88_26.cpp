#include <bits/stdc++.h>
using namespace std;
string solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n % 2 == 0) return "YES";
  for (int i = 0; i < n - 1; i++)
    if (a[i] > a[i + 1]) return "YES";
  return "NO";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }
  return 0;
}
