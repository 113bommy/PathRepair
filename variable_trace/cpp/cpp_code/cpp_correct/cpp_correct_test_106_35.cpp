#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  vector<long long int> v(n);
  cin >> n;
  for (int i = 2; i <= n + 1; i++) {
    cout << i << " ";
  }
  cout << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
