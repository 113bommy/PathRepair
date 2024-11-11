#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1), eps = 1e-8;
struct ele {
  double st, ed;
};
struct qq {
  double x;
  int d;
};
bool cmp(qq &a, qq &b) {
  if (a.x == b.x) {
    return a.d > b.d;
  }
  return a.x < b.x;
}
vector<ele> tru(double x, double y, double r) {
  double l = sqrt(x * x + y * y);
  vector<ele> ans;
  if (l >= 2 * r) {
    return ans;
  }
  double theta = atan2(x, y);
  if (theta < 0) theta += 2 * pi;
  double d = acos(l / 2 / r);
  double L = theta - d, R = theta + d;
  if (L < 0) {
    ans.push_back(ele{L + 2 * pi, 2 * pi});
    ans.push_back(ele{0, R});
  } else if (R > 2 * pi) {
    ans.push_back(ele{L, 2 * pi});
    ans.push_back(ele{0, R - 2 * pi});
  } else {
    ans.push_back(ele{L, R});
  }
  return ans;
}
int x[100010], y[100010];
int main() {
  int n, cnt;
  cin >> n >> cnt;
  int N = 0;
  for (int k = 0; k < n; k++) {
    cin >> x[N] >> y[N];
    if (x[N] == 0 && y[N] == 0) {
      cnt--;
      continue;
    }
    N++;
  }
  if (cnt <= 0) {
    cout << 0 << endl;
    return 0;
  }
  double l = 0, r = 2e5 + 1;
  for (int _t = 0; _t < 30; _t++) {
    vector<ele> tot;
    double m = (l + r) / 2;
    for (int k = 0; k < N; k++) {
      vector<ele> tmp = tru(x[k], y[k], m);
      for (int i = 0; i < tmp.size(); i++) {
        tot.push_back(tmp[i]);
      }
    }
    vector<qq> tt;
    for (int k = 0; k < tot.size(); k++) {
      tt.push_back(qq{tot[k].st, 1});
      tt.push_back(qq{tot[k].ed, -1});
    }
    sort(tt.begin(), tt.end(), cmp);
    int now = 0, mx = 0;
    for (int k = 0; k < tt.size(); k++) {
      now += tt[k].d;
      mx = max(mx, now);
    }
    if (mx >= cnt)
      r = m;
    else
      l = m;
  }
  printf("%.12f\n", l);
}
