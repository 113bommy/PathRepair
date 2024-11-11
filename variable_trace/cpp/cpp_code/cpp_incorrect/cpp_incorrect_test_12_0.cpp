#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int MOD = (int)1e9 + 7;
const int N = (int)5e7;
struct CHT {
  vector<pair<int, int> > lines;
  vector<pair<int, int> > st;
  int ind;
  int f(pair<int, int> p, int first) { return p.first * first + p.second; }
  bool check(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    return 1LL * (b.first - a.first) * (c.second - b.second) >=
           1LL * (c.first - b.first) * (b.second - a.second);
  }
  void clear() {
    lines.clear();
    st.clear();
    ind = 0;
  }
  void add(pair<int, int> p) { lines.push_back(p); }
  void build() {
    sort(lines.begin(), lines.end());
    reverse(lines.begin(), lines.end());
    for (auto &p : lines) {
      while ((int)st.size() >= 2 &&
             check(st[st.size() - 2], st[st.size() - 1], p))
        st.pop_back();
      st.push_back(p);
    }
  }
  int query(int first) {
    while (ind < (int)st.size() - 1 &&
           f(st[ind], first) > f(st[ind + 1], first))
      ind++;
    return f(st[ind], first);
  }
};
CHT cht;
int T;
int n, m;
long long ans;
char v[2005][2005];
int ind[2005];
vector<int> poles[2005];
int lgput(int n, long long p) {
  int ans = 1, first = n;
  while (p) {
    if (p & 1) ans = 1LL * ans * first % MOD;
    first = 1LL * first * first % MOD;
    p >>= 1;
  }
  return ans;
}
void precalc() {}
void solve() {
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    cin >> v[i];
    for (int j = 0; j <= m; j++) {
      if (v[i][j] == '1') poles[j].push_back(i);
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (poles[j].empty()) continue;
      if (poles[j][ind[j]] < i && ind[j] < (int)poles[j].size() - 1) {
        ind[j]++;
      }
    }
    cht.clear();
    for (int j = 0; j <= m; j++) {
      if (poles[j].empty()) continue;
      int p = ind[j];
      if (ind[j] && abs(i - poles[j][ind[j] - 1]) < abs(i - poles[j][ind[j]]))
        p = ind[j - 1];
      p = poles[j][p];
      cht.add(make_pair(-2 * j, j * j + (i - p) * (i - p)));
    }
    cht.build();
    for (int j = 0; j <= m; j++) {
      int val = cht.query(j) + j * j;
      ans += val;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  T = 1;
  precalc();
  for (; T; T--) {
    solve();
  }
  return 0;
}
