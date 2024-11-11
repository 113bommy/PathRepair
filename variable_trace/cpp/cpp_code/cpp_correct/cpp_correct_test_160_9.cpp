#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T& x) {
  x = 0;
  bool f = 0;
  char ch = (char)getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 1;
    ch = (char)getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch & 15);
    ch = (char)getchar();
  }
  if (f) x = -x;
}
template <typename T>
inline void write(T x) {
  if (x < 0) x = -x, putchar('-');
  static int st[45];
  int top = 0;
  do {
    st[top++] = x % 10;
    x /= 10;
  } while (x);
  while (top) putchar(st[--top] + '0');
  putchar('\n');
}
const long double pi = acos(-1.0);
const long double eps = (double)1e-7;
const long long mod = 1e9 + 7;
const int maxn = 1505;
const int maxm = 5005;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  int T;
  cin >> T;
  while (T--) {
    int n, m, a1, b1, a2, b2;
    cin >> n >> m >> a1 >> b1 >> a2 >> b2;
    int dx = 1, dy = 1;
    int ans = 0;
    while (a1 != a2 && b1 != b2) {
      if (a1 + dx < 1 || a1 + dx > n) dx = -dx;
      if (b1 + dy < 1 || b1 + dy > m) dy = -dy;
      a1 += dx;
      b1 += dy;
      ans++;
    }
    cout << ans << "\n";
  }
}
