#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2, p = 998244353;
int a[N], g[N], st[N], ys[N];
int n, tp, nowtot;
void inc(int &x, int y) {
  if ((x += y) >= p) x -= p;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i, j;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  g[0] = 1;
  for (i = 1; i <= n; i++) {
    int now = 0;
    while (tp && a[st[tp]] >= a[i]) {
      inc(now, ys[tp]);
      nowtot = (nowtot + (long long)(p - a[st[tp]] + a[i]) * ys[tp]) % p;
      --tp;
    }
    st[++tp] = i;
    nowtot = (nowtot + (long long)g[i - 1] * a[i]) % p;
    g[i] = (p - nowtot) % p;
    inc(now, g[i - 1]);
    ys[tp] = now;
  }
  if (n & 1)
    cout << (p - g[n]) % p << endl;
  else
    cout << g[n] << endl;
  return 0;
  for (i = 1; i <= n; i++)
    for (g[i] = 0, j = 0; j < i; j++)
      g[i] += -g[j] * *min_element(a + j + 1, a + i + 1);
  for (i = 1; i <= n; i++) cout << g[i] << " \n"[i == n];
  if (n & 1)
    cout << -g[n] << endl;
  else
    cout << g[n] << endl;
}
