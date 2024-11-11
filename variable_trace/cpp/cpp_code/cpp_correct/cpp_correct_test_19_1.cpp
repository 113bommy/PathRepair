#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int T, n;
int a[maxn];
bool flag[maxn], tmp[maxn];
bool check(int x) {
  for (int i = 0; i < a[1]; i++) flag[i] = 0;
  for (int i = a[1]; i <= x; i++) flag[i] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= x; j++) tmp[j] = flag[j], flag[j] = 0;
    for (int j = 0; j <= x; j++) {
      if (tmp[j] && j + a[i] <= x) flag[j + a[i]] = 1;
      if (tmp[j] && j - a[i] >= 0) flag[j - a[i]] = 1;
    }
  }
  bool ret = 0;
  for (int i = 0; i <= x; i++) ret |= flag[i];
  return ret;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int L = a[1], R = 3e3;
    while (L < R) {
      int mid = (L + R) >> 1;
      if (check(mid))
        R = mid;
      else
        L = mid + 1;
    }
    printf("%d\n", L);
  }
}
