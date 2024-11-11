#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 17;
int q, a, b, c;
void solve() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      a++;
    }
    if (s[i] == 'B') {
      b++;
    }
    if (s[i] == 'C') {
      c++;
    }
  }
  if (b == (a + c) && b >= a && b >= c) {
    cout << "YES\n";
  } else
    cout << "NO\n";
  a = 0;
  b = 0;
  c = 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
