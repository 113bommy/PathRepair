#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10, mod = 1e9 + 7;
template <typename T>
void Debug(T x, string s) {
  cout << s << ": " << x << endl;
}
const int maxn = 1e6 + 10;
int prime[maxn];
int visit[maxn];
void Prime() {
  visit[1] = 1;
  for (int i = 2; i < maxn; i++) {
    if (!visit[i]) {
      prime[++prime[0]] = i;
    }
    for (int j = 1; j <= prime[0] && i * prime[j] < maxn; j++) {
      visit[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        break;
      }
    }
  }
}
void solve() {
  int n;
  char c;
  cin >> n >> c;
  string s;
  cin >> s;
  vector<int> vec;
  for (int i = 0; i < n; i++) {
    if (s[i] != c) vec.push_back(i + 1);
  }
  if (!vec.size()) {
    cout << 0 << endl;
    return;
  }
  if (s[n - 1] == c) {
    cout << 1 << endl;
    cout << n << endl;
    return;
  }
  for (int i = n / 2 + 1; i <= n; i++) {
    if (s[i - 1] == c) {
      cout << 1 << endl;
      cout << i << endl;
      return;
    }
  }
  cout << 2 << endl;
  cout << n - 1 << " " << n << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Prime();
  int t;
  cin >> t;
  while (t--) solve();
}
