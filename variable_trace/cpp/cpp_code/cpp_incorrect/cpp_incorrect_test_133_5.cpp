#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void compute() {
  long long n;
  cin >> n;
  n -= 2;
  string s[n];
  cin >> s[0];
  string ans = s[0];
  for (long long i = 1; i < n; i++) {
    cin >> s[i];
    if (s[i][0] == ans[ans.size() - 1])
      ans.push_back(s[i][1]);
    else
      ans += s[i];
  }
  if (ans.size() != n) ans.push_back('a');
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    compute();
  }
  return 0;
}
