#include <bits/stdc++.h>
using namespace std;
const int N = 210000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = (int)1e9;
const double eps = 1e-9;
int n, k;
int px[N], py[N], num;
double angle[N];
pair<double, int> a[N];
int pp[N], f[N], tp[N];
double ang[N];
double sqr(double x) { return x * x; }
const double pi = acos(-1.0);
double cal(double theta) {
  if (theta >= pi) theta -= 2 * pi;
  if (theta <= -pi) theta += 2 * pi;
  return theta;
}
int check(double r) {
  int num = 0;
  int tk = k;
  for (int i = 1; i <= n; i++) {
    if (px[i] == 0 && py[i] == 0) {
      tk--;
      continue;
    }
    double dist = sqrt(sqr(px[i]) + sqr(py[i]));
    if (dist < 2 * r) {
      double theta = acos(dist / 2 / r);
      a[++num] = make_pair(cal(angle[i] - theta), i);
      a[++num] = make_pair(cal(angle[i] + theta), i);
    }
  }
  sort(a + 1, a + num + 1);
  memset(pp, 0, sizeof(pp));
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= num; i++) {
    int idx = a[i].second;
    if (!pp[idx])
      pp[idx] = i;
    else {
      double a1 = a[pp[idx]].first;
      double a2 = a[i].first;
      if (a2 - a1 > pi) {
        f[1]++;
        f[pp[idx] + 1]--;
        f[i]++;
      } else {
        f[pp[idx]]++;
        f[i + 1]--;
      }
    }
  }
  int cur = 0;
  if (cur >= tk) return 1;
  for (int i = 1; i <= num; i++) {
    cur += f[i];
    if (cur >= tk) return 1;
  }
  return 0;
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> px[i] >> py[i];
    angle[i] = atan2(py[i], px[i]);
  }
  double l = 0, r = 200000, ans;
  for (int i = 1; i <= 100; i++) {
    double mid = (l + r) / 2;
    if (check(mid))
      r = mid, ans = mid;
    else
      l = mid;
  }
  printf("%.10f\n", ans);
  return 0;
}
