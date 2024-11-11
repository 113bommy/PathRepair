#include <bits/stdc++.h>
using namespace std;
const long long N = 1e2 + 1e1 + 7;
long long n, m, k, P;
long long f[N][N][N], C[N][N];
void inc(long long &a, long long b) {
  a += b;
  a >= P ? a -= P : 0;
}
signed main() {
  scanf("%lld%lld%lld%lld", &n, &m, &k, &P);
  C[0][0] = 1;
  for (long long i = 1; i <= n; i++) {
    C[i][0] = 1;
    for (long long j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
  }
  for (long long i = 0; i <= n + 1; i++) f[0][0][i] = 1;
  for (long long d = n + 1; d >= 2; d--)
    for (long long l = 0; l < n; l++)
      for (long long lj = max(0ll, k + l - n); lj <= min(l, k); lj++)
        if (f[l][lj][d])
          for (long long r = 0; r < n - l; r++)
            for (long long rj = max(0ll, k + l + r - n - lj);
                 rj <= min(r, k - ((d - 1) == m) - lj); rj++)
              inc(f[l + r + 1][lj + rj + ((d - 1) == m)][d - 1],
                  C[l + r][l] * f[l][lj][d] % P * f[r][rj][d] % P);
  printf("%lld\n", f[n][k][1]);
}
