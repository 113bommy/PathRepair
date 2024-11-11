#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target_tbl( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx", "sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T>
void show(const vector<T> &a) {
  for (T x : a) cout << x << " ";
  cout << '\n';
}
template <class T>
void showline(const vector<T> &a) {
  for (T x : a) cout << x << '\n';
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());
long long xx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
long long yy[8] = {0, 0, 1, -1, -1, -1, 1, 1};
string dir = "RDLU";
string travel = "ENWS";
const long long N = 3e5 + 50, oo = 1e18 + 500;
const long long mod = 1e9 + 9;
const long long M2 = 1000000093, x2 = 27162;
const long long M1 = 1000000087, x1 = 241;
const long double eps = 1e-8, PI = 2 * acos(0.0);
long long ans = 0;
long long t[1010][1010];
long long n, m, q;
long long prv[1010];
long long cur[1010];
long long nxt[1010];
void upd(long long x, long long y) {
  long long zn = t[x][y] ? -1 : 1;
  fill(prv, prv + n, 0);
  fill(cur, cur + n, 0);
  fill(nxt, nxt + n, 0);
  long long y1, y2, y3;
  y1 = y - 1;
  y2 = y;
  y3 = y + 1;
  for (long long i = x; i >= 0; i--) {
    if (y1 >= 0 && y1 < m) {
      prv[i] = t[i][y1];
    }
    if (y2 >= 0 && y2 < m) {
      cur[i] = t[i][y2];
    }
    if (y3 >= 0 && y3 < m) {
      nxt[i] = t[i][y3];
    }
    y1--;
    y2--;
    y3--;
  }
  y1 = y - 1;
  y2 = y;
  y3 = y + 1;
  for (long long i = x; i < n; i++) {
    if (y1 >= 0 && y1 < m) {
      prv[i] = t[i][y1];
    }
    if (y2 >= 0 && y2 < m) {
      cur[i] = t[i][y2];
    }
    if (y3 >= 0 && y3 < m) {
      nxt[i] = t[i][y3];
    }
    y1++;
    y2++;
    y3++;
  }
  long long val = 0;
  {
    long long a = 0, b = 0;
    long long l = x, r = x;
    for (long long i = x - 1; i >= 0; i--) {
      if (prv[i] && cur[i]) {
        l = i;
        a++;
      } else
        break;
    }
    for (long long i = x + 1; i < n; i++) {
      if (prv[i] && cur[i]) {
        r = i;
        b++;
      } else
        break;
    }
    long long R = (r + 1 < n && cur[r + 1] == 0 && prv[r + 1] == 1);
    long long L = (l - 1 >= 0 && prv[l - 1] == 0 && cur[l - 1] == 1);
    val += 2 * b + R;
    if (prv[x])
      val += 4 * a * b + 2 * a + 2 * b + L * 2 * b + R * 2 * a + L * R + L + R;
  }
  {
    long long a = 0, b = 0;
    long long l = x, r = x;
    for (long long i = x - 1; i >= 0; i--) {
      if (nxt[i] && cur[i]) {
        l = i;
        a++;
      } else
        break;
    }
    for (long long i = x + 1; i < n; i++) {
      if (nxt[i] && cur[i]) {
        r = i;
        b++;
      } else
        break;
    }
    long long L = (l - 1 >= 0 && cur[l - 1] == 0 && nxt[l - 1] == 1);
    long long R = (r + 1 < n && nxt[r + 1] == 0 && cur[r + 1] == 1);
    val += 2 * a + L;
    if (nxt[x])
      val += 4 * a * b + 2 * a + 2 * b + L * 2 * b + R * 2 * a + L * R + L + R;
  }
  val++;
  if (prv[x]) val++;
  if (nxt[x]) val++;
  t[x][y] += zn;
  ans += zn * val;
}
signed main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n >> m >> q;
  vector<long long> diags;
  for (long long i = 0; i < n; i++) {
    diags.push_back(min(i + 1, m));
  }
  for (long long j = m - 2; j >= 0; j--) {
    diags.push_back(min(j + 1, m));
  }
  for (long long i = 0; i < ((long long)(diags.size())); i++) {
    ans += diags[i] * diags[i] +
           (i + 1 < ((long long)(diags.size())) ? diags[i] * diags[i + 1] : 0);
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      t[i][j] = 1;
    }
  }
  while (q--) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    upd(x, y);
    cout << ans << '\n';
  }
}
