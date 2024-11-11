#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5;
const long long MOD = 1000000007;
long long t, n, m, k, x, y, a, b;
void solve() {
  cin >> n >> k >> x;
  x--;
  string s;
  cin >> s;
  char c = 'a';
  vector<long long> v;
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      if (cnt == -1) {
        cnt++;
      }
      cnt += k;
    } else {
      if (cnt != -1) {
        cnt++;
        v.push_back(cnt);
      }
      cnt = -1;
    }
    c = s[i];
  }
  if (cnt != -1) {
    cnt++;
    v.push_back(cnt);
  }
  reverse(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    long long y = v[i];
    v[i] = x % y;
    x /= y;
  }
  reverse(v.begin(), v.end());
  long long pos = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      cout << 'a';
    } else {
      for (int j = 0; j < v[pos]; j++) {
        cout << 'b';
      }
      pos++;
      if (pos >= v.size()) {
        pos--;
      }
      if (i != n - 1) {
        while (i < n - 1 && s[i + 1] == '*') {
          i++;
          if (i == n - 1) {
            break;
          }
        }
      }
    }
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  cin >> t;
  while (t--) {
    solve();
  }
}
