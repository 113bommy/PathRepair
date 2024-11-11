#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test;
  cin >> test;
  while (test--) {
    long long int n, ans = 1;
    cin >> n;
    for (long long int i = 0; i < n; i++) {
      cout << ans << " ";
      ans = ans + 1;
    }
    cout << "\n";
  }
  return 0;
}
