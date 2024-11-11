#include <bits/stdc++.h>
using namespace std;
const int N = 510, p = 998244353;
int n, x, dp[N][N];
int c[N][N];
void init(int n) {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i; j++) {
      if (!j)
        c[i][j] = 1;
      else
        c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
    }
}
int qmi(int a, int k) {
  int res = 1;
  while (k) {
    if (k & 1) res = (long long)res * a % p;
    a = (long long)a * a % p;
    k >>= 1;
  }
  return res;
}
long long dfs(int now, int k) {
  if (now == 0) return 1;
  if (now == 1) return 0;
  int &v = dp[now][k];
  if (v) return v;
  if (now > k) {
    return v = qmi(k, now);
  }
  for (int i = 0; i <= now; i++) {
    v = (v + (long long)dfs(now - i, k - now + 1) * c[now][i] % p *
                 qmi(now - 1, i) % p) %
        p;
  }
  return v;
}
int main() {
  scanf("%d%d", &n, &x);
  init(N - 1);
  printf("%d\n", dfs(n, x));
}
