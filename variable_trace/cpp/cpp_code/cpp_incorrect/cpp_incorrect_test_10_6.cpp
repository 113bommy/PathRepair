#include <bits/stdc++.h>
using namespace std;
int n, m, k, res;
const int mo = 1000000007;
pair<int, int> a, b, c, d;
int ksm(int x, long long y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = 1ll * ans * x % mo;
    x = 1ll * x * x % mo;
    y = y / 2;
  }
  return ans;
}
int main() {
  res = 1;
  scanf("%d%d%d%d%d", &n, &m, &k, &c.first, &c.second);
  scanf("%d%d%d%d", &a.first, &a.second, &b.first, &b.second);
  if (a > b) swap(a, b);
  int doit = 1;
  while (doit) {
    if (a == b) {
      res = 1ll * res * ksm(k, 1ll * n * m);
      break;
    }
    d = make_pair(0, 0);
    if (a.first + c.first - 1 >= d.first) {
      if (a.second <= b.second && a.second + c.second - 1 >= b.second) {
        d = make_pair(a.first + c.first - b.first,
                      a.second + c.second - b.second);
      } else if (a.second >= b.second && b.second + c.second - 1 >= a.second) {
        d = make_pair(a.first + c.first - b.first,
                      b.second + c.second - a.second);
        b.second = a.second;
        a.second = a.second + c.second - d.second;
      }
    }
    res = 1ll * res *
          ksm(k, 1ll * n * m - 2ll * c.first * c.second +
                     1ll * d.first * d.second) %
          mo;
    n = c.first;
    m = c.second;
    c = d;
    if (c.first == 0) {
      doit = 0;
      res = 1ll * res * ksm(k, 1ll * n * m) % mo;
    }
  }
  printf("%d\n", res);
}
