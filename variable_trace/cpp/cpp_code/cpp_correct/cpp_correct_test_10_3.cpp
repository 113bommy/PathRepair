#include <bits/stdc++.h>
using namespace std;
long long solve(long long r, long long c, long long dr, long long dc) {
  if (dr == 0 && dc == 0) {
    return r * c;
  }
  if (dr >= r || dc >= c) {
    return r * c;
  }
  if (r >= 2 * dr || c >= 2 * dc) return r * c - (r - dr) * (c - dc);
  return r * c - solve(r - dr, c - dc, 2 * dr - r, 2 * dc - c);
}
long long lgput(long long b, long long e, long long mod) {
  long long ret = 1;
  while (e) {
    if (e & 1) ret = (ret * b) % mod;
    b = (b * b) % mod;
    e /= 2;
  }
  return ret;
}
int32_t main() {
  long long n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  long long ax, bx, ay, by;
  cin >> ax >> ay >> bx >> by;
  long long ccrect = solve(r, c, abs(bx - ax), abs(by - ay));
  long long aria = n * m;
  aria -= 2 * r * c;
  long long dr = abs(bx - ax), dc = abs(by - ay);
  if (dr < r && dc < c) aria += (r - dr) * (c - dc);
  aria += ccrect;
  cout << lgput(k, aria, 1000 * 1000 * 1000 + 7) << endl;
  return 0;
}
