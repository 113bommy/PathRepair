#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 100, INF = 1e9 + 7;
int kase, n, a[N], s[2100], t[2100];
bool check(int x) {
  for (int i = 0; i <= x; i++) s[i] = 1;
  for (int i = 1; i <= n; i++) {
    memset(t, 0, sizeof t);
    for (int j = a[i]; j <= x; j++) t[j - a[i]] = s[j];
    for (int j = x - a[i]; j >= 0; j--) t[j + a[i]] = s[j];
    for (int j = 0; j <= x; j++) s[j] = t[j];
  }
  for (int i = 0; i <= x; i++)
    if (s[i]) return true;
  return false;
}
int main() {
  scanf("%d", &kase);
  while (kase--) {
    scanf("%d", &n);
    int max_ = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      max_ = max(max_, a[i]);
    }
    int l = max_, r = max_ * 2;
    while (l < r) {
      int m = (l + r) / 2;
      if (check(m))
        r = m;
      else
        l = m + 1;
    }
    printf("%d\n", l);
  }
}
