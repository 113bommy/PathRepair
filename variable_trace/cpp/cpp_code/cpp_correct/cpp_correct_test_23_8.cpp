#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return f == -1 ? ~x + 1 : x;
}
long long n, m;
long long a[4010];
long long ls[4010], rs[4010];
long long stk[4010], top;
void build() {
  for (long long i = 1; i <= n; ++i) {
    while (top && a[stk[top]] > a[i]) {
      rs[stk[top]] = ls[i], ls[i] = stk[top];
      --top;
    }
    if (top) rs[stk[top]] = i;
    stk[++top] = i;
  }
}
long long sz[4010], dp[4010][4010], tmp[4010];
void dfs(long long x) {
  sz[x] = 1;
  dp[x][1] = (m - 1) * a[x];
  if (ls[x]) {
    dfs(ls[x]);
    for (long long i = 0; i <= sz[x] + sz[ls[x]]; ++i) tmp[i] = 0;
    for (long long i = 0; i <= sz[x]; ++i) {
      for (long long j = 0; j <= sz[ls[x]]; ++j) {
        tmp[i + j] =
            max(tmp[i + j], dp[x][i] + dp[ls[x]][j] - 2 * i * j * a[x]);
      }
    }
    sz[x] += sz[ls[x]];
    for (long long i = 0; i <= sz[x]; ++i) dp[x][i] = tmp[i];
  }
  if (rs[x]) {
    dfs(rs[x]);
    for (long long i = 0; i <= sz[x] + sz[rs[x]]; ++i) tmp[i] = 0;
    for (long long i = 0; i <= sz[x]; ++i) {
      for (long long j = 0; j <= sz[rs[x]]; ++j) {
        tmp[i + j] =
            max(tmp[i + j], dp[x][i] + dp[rs[x]][j] - 2 * i * j * a[x]);
      }
    }
    sz[x] += sz[rs[x]];
    for (long long i = 0; i <= sz[x]; ++i) dp[x][i] = tmp[i];
  }
}
signed main() {
  n = read(), m = read();
  for (long long i = 1; i <= n; ++i) a[i] = read();
  build();
  dfs(stk[1]);
  printf("%lld\n", dp[stk[1]][m]);
}
