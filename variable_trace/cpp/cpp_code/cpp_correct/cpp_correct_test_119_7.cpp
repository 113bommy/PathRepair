#include <bits/stdc++.h>
using namespace std;
int t;
void solve() {
  int n;
  cin >> n;
  long long A[n + 1];
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    ans += A[i];
  }
  if (ans % n == 0)
    cout << 0;
  else
    cout << 1;
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
