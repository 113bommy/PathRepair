#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
long long t, n, arr[MAXN], h, sub[MAXN], cnt, add[MAXN];
bool check(long long x) {
  long long res = n;
  int idx = lower_bound(sub, sub + cnt + 1, x - 1) - sub;
  res += add[idx - 1] + (x - 1) * (n - idx + 1);
  if (res >= h) return true;
  return false;
}
int main() {
  scanf("%lld", &t);
  while (t--) {
    cnt = 0;
    memset(sub, 0, sizeof(sub));
    memset(add, 0, sizeof(add));
    scanf("%lld%lld", &n, &h);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &arr[i]);
      if (i > 1) sub[++cnt] = arr[i] - arr[i - 1] - 1;
    }
    sort(sub + 1, sub + cnt + 1);
    for (int i = 1; i <= cnt; ++i) add[i] = add[i - 1] + sub[i];
    long long l = 1, r = 1e18;
    while (l < r) {
      long long mid = (l + r) >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }
    printf("%lld\n", l);
  }
}
