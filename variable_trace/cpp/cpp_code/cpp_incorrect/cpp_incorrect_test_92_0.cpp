#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long double PI = 3.14159265358979323846;
const long double EPS = 0.000000001;
const long long MD_7 = 1000000007;
const long long MD_9 = 1000000009;
const long long MD = 228228227;
const long long INF = 1e16;
void solve() {
  string str;
  cin >> str;
  if (str[0] == str.back()) {
    cout << str << '\n';
    return;
  }
  if (str[0] == 'a')
    cout << 'b';
  else
    cout << 'a';
  for (long long i = 1; i < (long long)(str.size()) - 1; ++i) cout << str[i];
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
