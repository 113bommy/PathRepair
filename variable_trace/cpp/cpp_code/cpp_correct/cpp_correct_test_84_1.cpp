#include <bits/stdc++.h>
const long long INF = 1e16;
const int M = 1e5 + 5;
int n, k, tot;
bool vis[M];
int prime[M];
long long phi[M], f[M][18];
inline void Init() {
  phi[1] = 1;
  for (int i = 2; i < M; ++i) {
    if (!vis[i]) prime[++tot] = i, phi[i] = i - 1;
    for (int j = 1; j <= tot && prime[j] * i < M; ++j) {
      vis[prime[j] * i] = 1;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      }
      phi[i * prime[j]] = phi[i] * (prime[j] - 1);
    }
  }
  for (int i = 2; i < M; ++i) phi[i] += phi[i - 1];
}
inline long long c(int L, int R) {
  if (L > R) return INF;
  long long res = 0;
  for (int l = L, r; l <= R; l = r + 1) {
    r = R / (R / l);
    res += 1ll * phi[R / l] * (r - l + 1);
  }
  return res;
}
inline void Solve(int t, int l, int r, int ql, int qr) {
  if (ql > qr || l > r) return;
  int mid = ql + qr >> 1, pos = l;
  long long val = c(std ::min(r, mid) + 1, mid);
  for (int i = std ::min(r, mid); i >= l; --i) {
    if (f[mid][t] > f[i][t - 1] + val) f[mid][t] = f[i][t - 1] + val, pos = i;
    if (val == INF)
      val = phi[mid / i];
    else
      val += phi[mid / i];
  }
  Solve(t, l, pos, ql, mid - 1);
  Solve(t, pos, r, mid + 1, qr);
}
inline int read() {
  int f = 1, s = 0;
  char ch = getchar();
  while (!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar();
  while (isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return f * s;
}
int main() {
  Init();
  for (int i = 0; i < 18; ++i)
    for (int j = 0; j < M; ++j) f[j][i] = INF;
  f[0][0] = 0;
  for (int i = 1; i < M; ++i) f[i][1] = 1ll * i * (i + 1) / 2;
  for (int i = 2; i < 18; ++i) Solve(i, 1, M - 5, 1, M - 5);
  int t = read();
  while (t--) {
    int n = read(), k = read();
    if (k >= 18 || (1 << k) > n) {
      std ::cout << n << '\n';
      continue;
    }
    std ::cout << f[n][k] << '\n';
  }
  return 0;
}
