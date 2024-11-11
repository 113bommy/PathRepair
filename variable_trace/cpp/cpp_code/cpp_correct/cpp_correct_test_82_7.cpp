#include <bits/stdc++.h>
using namespace std;
int n, q, k;
int a[300015], Min[300015][21], Log[300015];
long long ans[300015];
vector<int> vec[300015];
vector<pair<pair<int, int>, int>> que[300015];
int query(int l, int r) {
  int k = Log[r - l + 1];
  return min(Min[l][k], Min[r - (1 << k) + 1][k]);
}
vector<pair<int, int>> stk;
int lazy[300015 << 2];
long long sum[300015 << 2];
void init(int m) {
  for (int i = (1); i <= (m * 4); i++) lazy[i] = sum[i] = 0;
}
void pushup(int p) { sum[p] = sum[(p << 1)] + sum[(p << 1 | 1)]; }
void down(int p, int l, int r, int v) {
  lazy[p] = v;
  sum[p] = (long long)(r - l + 1) * v;
}
void pushdown(int p, int l, int r) {
  if (lazy[p]) {
    int mid = (l + r) >> 1;
    down((p << 1), l, mid, lazy[p]);
    down((p << 1 | 1), mid + 1, r, lazy[p]);
    lazy[p] = 0;
  }
}
void modify(int p, int l, int r, int x, int y, int v) {
  if (x <= l && r <= y) return down(p, l, r, v);
  int mid = (l + r) >> 1;
  pushdown(p, l, r);
  if (x <= mid) modify((p << 1), l, mid, x, y, v);
  if (y > mid) modify((p << 1 | 1), mid + 1, r, x, y, v);
  pushup(p);
}
long long query(int p, int l, int r, int x, int y) {
  if (x <= l && r <= y) return sum[p];
  pushdown(p, l, r);
  int mid = (l + r) >> 1;
  long long res = 0;
  if (x <= mid) res += query((p << 1), l, mid, x, y);
  if (y > mid) res += query((p << 1 | 1), mid + 1, r, x, y);
  return res;
}
void solve(int x) {
  int m = ((int)vec[x].size()), ptr = ((int)que[x].size()) - 1;
  init(m);
  stk.clear();
  for (int i = (m - 1); i >= (0); i--) {
    int r = i;
    while (((int)stk.size()) > 0 && stk.back().second >= vec[x][i])
      r = stk.back().first, stk.pop_back();
    stk.push_back(make_pair(r, vec[x][i]));
    modify(1, 1, m, i + 1, r + 1, vec[x][i]);
    while (ptr >= 0 && que[x][ptr].first.first == i) {
      int len = que[x][ptr].first.second;
      assert(i + len <= m);
      ans[que[x][ptr].second] = (long long)a[i * k + (x == 0 ? k : x)] +
                                (len > 0 ? query(1, 1, m, i + 1, i + len) : 0);
      ptr--;
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &q, &k);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]), Min[i][0] = a[i];
  for (int i = (2); i <= (n); i++) Log[i] = Log[i >> 1] + 1;
  for (int j = (1); j <= (19); j++) {
    for (int i = (1); i <= (n); i++) {
      if (i + (1 << j) - 1 > n) break;
      Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
    }
  }
  for (int i = (1); i <= (n); i++)
    vec[i % k].push_back(query(i, min(n, i + k)));
  for (int i = (1); i <= (q); i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    que[l % k].push_back(make_pair(make_pair((l - 1) / k, (r - l) / k), i));
  }
  for (int i = (0); i <= (k - 1); i++) sort(que[i].begin(), que[i].end());
  for (int i = (0); i <= (k - 1); i++) solve(i);
  for (int i = (1); i <= (q); i++) printf("%lld\n", ans[i]);
  return 0;
}
