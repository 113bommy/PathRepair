#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
struct node {
  int x, y;
} b[200000 + 5], a[200000 + 5], s;
bool operator==(node A, node B) { return A.x == B.x && A.y == B.y; }
bool cmp(node A, node B) { return A.x < B.x || (A.x == B.x && A.y < B.y); }
int n;
double dis(node A, node B) {
  return sqrt(double(A.x - B.x) * (A.x - B.x) +
              double(A.y - B.y) * (A.y - B.y));
}
void work_x() {
  int i, j, k = 0;
  for (i = 1; i <= n; i++)
    if (a[i].x == a[1].x)
      b[++k] = a[i];
    else
      b[0] = a[i];
  for (i = 1; i < n; i++) a[i] = b[i];
  n--;
  sort(a + 1, a + n + 1, cmp);
  if (s == b[0])
    printf("%.8lf\n", min(dis(b[0], a[1]), dis(b[0], a[n])) + dis(a[1], a[n]));
  else {
    if (s == a[n]) reverse(a + 1, a + n + 1);
    if (s == a[1]) {
      double ans = dis(a[1], a[n]) + dis(a[n], b[0]);
      for (i = 1; i < n; i++) {
        ans = min(ans, dis(a[1], a[i]) + dis(a[i], b[0]) + dis(a[i + 1], a[n]) +
                           min(dis(a[i + 1], b[0]), dis(a[n], b[0])));
      }
      printf("%.8lf\n", ans);
    } else {
      int id;
      for (i = 1; i <= n; i++)
        if (a[i] == s) id = i;
      double ans =
          min(dis(a[id], a[1]) + dis(a[id + 1], a[n]) + dis(a[1], b[0]) +
                  min(dis(a[n], b[0]), dis(a[id + 1], b[0])),
              dis(a[id - 1], a[1]) + dis(a[id], a[n]) + dis(a[n], b[0]) +
                  min(dis(a[i - 1], b[0]), dis(a[1], b[0])));
      for (i = id + 1; i <= n; i++)
        ans =
            min(ans, dis(a[1], a[id]) + dis(a[1], a[id + 1]) +
                         dis(a[id + 1], a[i]) + dis(a[i], b[0]) +
                         (i != n) * (min(dis(b[0], a[i + 1]), dis(b[0], a[n])) +
                                     dis(a[i + 1], a[n])));
      for (i = 1; i < id; i++)
        ans =
            min(ans, dis(a[n], a[id]) + dis(a[n], a[id - 1]) +
                         dis(a[id - 1], a[i]) + dis(a[i], b[0]) +
                         (i != 1) * (min(dis(b[0], a[i - 1]), dis(b[0], a[1])) +
                                     dis(a[i - 1], a[1])));
      printf("%.8lf\n", ans);
    }
  }
}
void work(double f) {
  int i, j, k = 0;
  for (i = 1; i <= n; i++)
    if (fabs(a[i].y - (f * (a[i].x - a[1].x) + a[1].y)) < eps)
      b[++k] = a[i];
    else
      b[0] = a[i];
  for (i = 1; i < n; i++) a[i] = b[i];
  n--;
  sort(a + 1, a + n + 1, cmp);
  if (s == b[0])
    printf("%.8lf\n", min(dis(b[0], a[1]), dis(b[0], a[n])) + dis(a[1], a[n]));
  else {
    if (s == a[n]) reverse(a + 1, a + n + 1);
    if (s == a[1]) {
      double ans = dis(a[1], a[n]) + dis(a[n], b[0]);
      for (i = 1; i < n; i++) {
        ans = min(ans, dis(a[1], a[i]) + dis(a[i], b[0]) + dis(a[i + 1], a[n]) +
                           min(dis(a[i + 1], b[0]), dis(a[n], b[0])));
      }
      printf("%.8lf\n", ans);
    } else {
      int id;
      for (i = 1; i <= n; i++)
        if (a[i] == s) id = i;
      double ans =
          min(dis(a[id], a[1]) + dis(a[id + 1], a[n]) + dis(a[1], b[0]) +
                  min(dis(a[n], b[0]), dis(a[id + 1], b[0])),
              dis(a[id - 1], a[1]) + dis(a[id], a[n]) + dis(a[n], b[0]) +
                  min(dis(a[i - 1], b[0]), dis(a[1], b[0])));
      for (i = id + 1; i <= n; i++)
        ans =
            min(ans, dis(a[1], a[id]) + dis(a[1], a[id + 1]) +
                         dis(a[id + 1], a[i]) + dis(a[i], b[0]) +
                         (i != n) * (min(dis(b[0], a[i + 1]), dis(b[0], a[n])) +
                                     dis(a[i + 1], a[n])));
      for (i = 1; i < id; i++)
        ans =
            min(ans, dis(a[n], a[id]) + dis(a[n], a[id - 1]) +
                         dis(a[id - 1], a[i]) + dis(a[i], b[0]) +
                         (i != 1) * (min(dis(b[0], a[i - 1]), dis(b[0], a[1])) +
                                     dis(a[i - 1], a[1])));
      printf("%.8lf\n", ans);
    }
  }
}
int main() {
  int m, i, j, k = 0;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d%d", &b[i].x, &b[i].y);
  s = b[m];
  sort(b + 1, b + n + 1, cmp);
  a[++k] = b[1];
  for (i = 2; i <= n; i++)
    if (b[i].x != b[i - 1].x || b[i].y != b[i - 1].y) a[++k] = b[i];
  n = k;
  if (n == 1) {
    printf("0.000000\n");
    return 0;
  }
  if (n == 2) {
    printf("%.8lf\n", dis(a[1], a[2]));
    return 0;
  }
  k = 0;
  for (i = 1; i <= n; i++) k += a[i].x == a[1].x;
  if (k == n - 1) {
    work_x();
    return 0;
  }
  swap(a[1], a[2]);
  k = 0;
  for (i = 1; i <= n; i++) k += a[i].x == a[1].x;
  if (k == n - 1) {
    work_x();
    return 0;
  }
  double f;
  if (a[1].x != a[2].x) {
    f = double(a[2].y - a[1].y) / (a[2].x - a[1].x);
    k = 0;
    for (i = 1; i <= n; i++)
      k += fabs(a[i].y - (f * (a[i].x - a[1].x) + a[1].y)) < eps;
    if (k == n - 1) {
      work(f);
      return 0;
    }
  }
  swap(a[1], a[3]);
  f = double(a[2].y - a[1].y) / (a[2].x - a[1].x);
  k = 0;
  for (i = 1; i <= n; i++)
    k += fabs(a[i].y - (f * (a[i].x - a[1].x) + a[1].y)) < eps;
  if (k == n - 1) {
    work(f);
    return 0;
  }
  swap(a[2], a[3]);
  f = double(a[2].y - a[1].y) / (a[2].x - a[1].x);
  k = 0;
  for (i = 1; i <= n; i++)
    k += fabs(a[i].y - (f * (a[i].x - a[1].x) + a[1].y)) < eps;
  if (k == n - 1) {
    work(f);
    return 0;
  }
}
