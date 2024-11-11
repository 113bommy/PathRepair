#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 2;
inline void solve() {
  string s;
  cin >> s;
  long long a = 0, b = 0, c = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'A') a++;
    if (s[i] == 'B') b++;
    if (s[i] == 'C') c++;
  }
  if (b >= (a + c))
    return void(cout << "YES"
                     << "\n");
  return void(cout << "NO"
                   << "\n");
}
int main() {
  ios_base::sync_with_stdio(0);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
