#include <bits/stdc++.h>
using namespace std;
char s[10][10001];
int X[10];
pair<int, vector<int>> Calculate(int n, int m, int mask) {
  vector<pair<int, int>> v(m);
  for (int k = 0; k < m; ++k) {
    int c = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i][k] == '0') {
        continue;
      }
      c += ((mask & (1 << i)) != 0) ? 1 : -1;
    }
    v[k] = {c, k};
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int c = ((mask & (1 << i)) != 0) ? -1 : 1;
    ans += c * X[i];
  }
  vector<int> p(m);
  sort(v.begin(), v.end());
  for (int k = 0; k < m; ++k) {
    ans += v[k].first * (k + 1);
    p[v[k].second] = k + 1;
  }
  return {ans, p};
}
void Solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &X[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  pair<int, vector<int>> ans = {INT_MIN, vector<int>()};
  for (int mask = 0; mask < (1 << n); ++mask) {
    ans = max(ans, Calculate(n, m, mask));
  }
  auto [_, p] = ans;
  for (int pi : p) {
    printf("%d ", pi);
  }
  printf("\n");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    Solve();
  }
  return 0;
}
