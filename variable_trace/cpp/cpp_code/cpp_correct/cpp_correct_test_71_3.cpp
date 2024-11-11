#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const double eps = 1e-10;
struct Point {
  int x, y, id, rnk;
} p1[N];
int n, m, s, p;
bool ok[N];
double ans, tot;
bool cmp(Point i, Point j) {
  if (i.x != j.x) return i.x < j.x;
  return i.y < j.y;
}
bool cmp1(Point i, Point j) { return i.rnk < j.rnk; }
inline bool check(Point i, Point j, Point k) {
  return 1ll * (j.x - i.x) * (k.y - j.y) == 1ll * (k.x - j.x) * (j.y - i.y);
}
inline double dis(int i, int j) {
  return sqrt(1.0 * (p1[i].x - p1[j].x) * (p1[i].x - p1[j].x) +
              1.0 * (p1[i].y - p1[j].y) * (p1[i].y - p1[j].y));
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &p1[i].x, &p1[i].y), p1[i].id = i;
  if (n == 3) {
    double tmp[3];
    ans = dis(1, 2) + dis(2, 3) + dis(3, 1);
    for (int i = 1, j = 0; i <= 3; ++i) {
      if (i != m) tmp[++j] = dis(i, m);
    }
    ans -= max(tmp[1], tmp[2]);
    printf("%lf\n", ans);
    return 0;
  }
  sort(p1 + 1, p1 + n + 1, cmp);
  for (int i = 1; i <= n; ++i) p1[i].rnk = i;
  p = 0;
  for (int i = 2; i < n; ++i) ok[i] = check(p1[i - 1], p1[i], p1[i + 1]);
  for (int i = 2; i < n; ++i)
    if (!ok[i - 1] && !ok[i] && !ok[i + 1]) p = i;
  if (!p && !ok[2])
    p = 1;
  else if (!p)
    p = n;
  p1[p].rnk = n + 1;
  sort(p1 + 1, p1 + n + 1, cmp1);
  for (int i = 1; i <= n; ++i)
    if (p1[i].id == m) s = i;
  if (s != n) {
    ans = min(dis(s, n - 1) + dis(n - 1, 1) + dis(1, n),
              dis(s, 1) + dis(1, n - 1) + dis(n - 1, n));
    for (int i = s; i < n - 1; ++i) {
      tot = min(
          dis(s, i) + dis(i, 1) + dis(1, n) + dis(n, i + 1) + dis(i + 1, n - 1),
          dis(s, 1) + dis(1, i) + dis(i, n) + dis(n, i + 1) +
              dis(i + 1, n - 1));
      ans = min(ans, tot);
    }
    for (int i = 2; i <= s; ++i) {
      tot = min(dis(s, i) + dis(n - 1, i) + dis(n - 1, n) + dis(n, i - 1) +
                    dis(i - 1, 1),
                dis(s, n - 1) + dis(n - 1, i) + dis(i, n) + dis(n, i - 1) +
                    dis(i - 1, 1));
      ans = min(ans, tot);
    }
  } else
    ans = dis(1, n - 1) + min(dis(1, n), dis(n - 1, n));
  printf("%lf\n", ans);
  return 0;
}
