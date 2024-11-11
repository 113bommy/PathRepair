#include <bits/stdc++.h>
using namespace std;
long long a[100005];
signed main() {
  for (long long i = 1; i <= 100002; i++) {
    a[i] = a[i - 1] + i;
  }
  long long t;
  scanf("%lld", &t);
  long long n, m, k;
  while (t--) {
    scanf("%lld %lld %lld", &n, &m, &k);
    if (n == 1) {
      if (k >= 2 && m <= a[n - 1])
        printf("YES\n");
      else
        printf("NO\n");
    } else if (k <= 2) {
      printf("NO\n");
    } else if (k == 3) {
      if (n > 100000 || m < a[n - 1] || m > a[n - 1])
        printf("NO\n");
      else
        printf("YES\n");
    } else {
      if (m >= (n - 1) && (n > 100000 || m <= a[n - 1]))
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
