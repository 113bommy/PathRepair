#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int ans;
    if (rd - rb >= 0)
      ans = rd - rb;
    else
      ans = 2 * n - (rd + rb);
    if (cd - cb >= 0)
      ans = min(ans, cd - cb);
    else
      ans = min(ans, 2 * m - (rd + rb));
    cout << ans << endl;
  }
  return 0;
}
