#include <bits/stdc++.h>
using namespace std;
const int N = 103;
int n, P;
int f[N][N][N], fc[N], C[N][N];
inline int add(const int &a, const int &b) {
  return a + b >= P ? a + b - P : a + b;
}
int cl(int i, int j, int k) {
  if (i == 0) return k == 0;
  if (j == 0) return k == 1 ? fc[i] : 0;
  if (i <= j) return k == 0 ? fc[i] : 0;
  if (j + k > i) return 0;
  register int &g = f[i][j][k];
  if (g != -1) return g;
  g = 0;
  for (register int a = 0; a < i; a++) {
    register int h = 0;
    for (register int b = max(0, k + a - i + 1); b <= k && b <= a; b++)
      h = (h + 1ll * cl(i - a - 1, j - 1, k - b) * cl(a, j - 1, b)) % P;
    g = (g + 1ll * h * C[i - 1][a]) % P;
  }
  return g;
}
int main() {
  int m, k;
  scanf("%d%d%d%d", &n, &m, &k, &P);
  memset(f, -1, sizeof f);
  fc[0] = 1;
  for (register int i = 1; i <= n; i++) fc[i] = 1ll * fc[i - 1] * i % P;
  for (register int i = 0; i <= n; i++)
    for (register int j = 0; j <= i; j++) {
      if (j == 0)
        C[i][j] = 1;
      else
        C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
    }
  printf("%d", cl(n, m + 1, k));
  return 0;
}
