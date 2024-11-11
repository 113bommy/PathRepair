#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  long long s = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    s += a;
  }
  if (s % n == 0)
    cout << "1\n";
  else
    cout << "0\n";
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
