#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long ret = 0;
  char c = getchar(), sign = c;
  while (c < '0' || c > '9') sign = c, c = getchar();
  while (c >= '0' && c <= '9') ret = ret * 10 + (c ^ 48), c = getchar();
  return sign == '-' ? -ret : ret;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const double eps = 1e-5;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const int INF = 0x7fffffff;
const int MOD = 1e9 + 7;
const int N = 1e6 + 10;
int n, mx[N];
bool ans[N];
struct Node {
  int a, b, id;
} w[N];
void init() {}
void solve() {
  memset(ans, false, sizeof(ans));
  n = read();
  for (int i = 1; i <= n; i++) w[i].a = read();
  for (int i = 1; i <= n; i++) w[i].b = read(), w[i].id = i;
  sort(w + 1, w + n + 1, [](Node &n1, Node &n2) { return n1.a < n2.a; });
  for (int i = 1; i <= n; i++) mx[i] = max(mx[i - 1], w[i].b);
  int t = w[n].b;
  ans[n] = true;
  for (int i = n - 1; i >= 1; i--) {
    if (mx[i] > t)
      ans[w[i].id] = true;
    else
      break;
    t = min(t, w[i].b);
  }
  for (int i = 1; i <= n; i++) putchar('0' + ans[i]);
  puts("");
}
int main(void) {
  init();
  for (int _ = read(); _--;) solve();
  return 0;
}
