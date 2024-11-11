#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
constexpr int MAXN = 1e6 + 5;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 1;
constexpr int LOG = 3e1 + 1;
constexpr int SQ = 500;
constexpr int ALP = 5e3 + 3;
int n;
int a[MAXN];
bool mark[ALP][ALP], has[ALP];
vector<int> G[ALP], ans;
void add(int idx, int x) {
  for (int i = idx + 1; i <= 5000; i++) {
    if (!mark[i][x]) {
      G[i].push_back(x);
      mark[i][x] = true;
    } else {
      break;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= 5000; i++) {
    G[i].push_back(0);
    mark[i][0] = true;
  }
  ans.push_back(0);
  has[0] = true;
  for (int i = 1; i <= n; i++) {
    int ptr = 0;
    while (ptr < G[a[i]].size()) {
      int x = G[a[i]][ptr++] ^ a[i];
      if (!has[x]) {
        ans.push_back(x);
        has[x] = true;
      }
      add(a[i], x);
    }
    G[a[i]].clear();
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (auto x : ans) {
    cout << x << " ";
  }
  return 0;
}
