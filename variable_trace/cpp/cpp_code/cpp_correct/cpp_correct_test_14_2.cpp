#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
long long tot;
struct que {
  long long x, y, z;
} t[1000005];
int main() {
  long long tt;
  scanf("%lld", &tt);
  while (tt--) {
    long long n;
    tot = 0;
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (long long i = 1; i <= n; i++) {
      long long mi = i;
      for (long long j = i + 1; j <= n; j++)
        if (a[mi] > a[j]) mi = j;
      long long k = a[mi];
      for (long long j = mi - 1; j >= i; j--) a[j + 1] = a[j];
      a[i] = k;
      if (mi != i) t[++tot].x = i, t[tot].y = mi, t[tot].z = mi - i;
    }
    printf("%lld\n", tot);
    for (long long i = 1; i <= tot; i++)
      printf("%lld %lld %lld\n", t[i].x, t[i].y, t[i].z);
  }
  return 0;
}
