#include <bits/stdc++.h>
#pragma GCC optimize(2, 3, "Ofast")
using namespace std;
template <typename T1, typename T2>
void ckmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
const int N = 505;
char a[N], b[N];
int go[N][2], dp[2][N][N];
int kmp[N];
int n, m;
int main() {
  n = read(), m = read();
  scanf("%s", a + 1);
  for (int i = 1; i <= n; i++) a[i] -= '0';
  scanf("%s", b + 1);
  for (int i = 1; i <= m; i++) b[i] -= '0';
  b[m + 1] = 114;
  for (int i = 2, j = 0; i <= m; i++) {
    while (j && b[i] != b[j + 1]) j = kmp[j];
    if (b[i] == b[j + 1]) j++;
    kmp[i] = j;
  }
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j < 2; j++) {
      int t = i;
      while (t && j != b[t + 1]) t = kmp[t];
      if (j == b[t + 1]) t++;
      go[i][j] = t;
    }
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0][0] = 0;
  int now = 0;
  for (int i = 1; i <= n; i++) {
    now ^= 1;
    memset(dp[now], 0x3f, sizeof(dp[now]));
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= i; k++) {
        for (int t = 0; t < 2; t++) {
          int coef = t != a[i];
          ckmin(dp[now][go[j][t]][k + (go[j][t] == m)],
                dp[now ^ 1][j][k] + coef);
        }
      }
    }
  }
  for (int k = 0; k <= n - m + 1; k++) {
    int t = 1e9;
    for (int j = 0; j <= m; j++) ckmin(t, dp[now][j][k]);
    if (t == 1e9) t = -1;
    print(t, " \n"[k == n - m + 1]);
  }
  return 0;
}
