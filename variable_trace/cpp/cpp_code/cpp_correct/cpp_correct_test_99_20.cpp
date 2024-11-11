#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long x, n, a, ans;
    scanf("%lld%lld", &x, &n);
    if (x % 2 == 0) {
      a = n % 4;
      ans = (a == 1 ? x - n : a == 2 ? x + 1 : a == 3 ? x + 1 + n : x);
    } else {
      a = n % 4;
      ans = (a == 1 ? x + n : a == 2 ? x - 1 : a == 3 ? x - 1 - n : x);
    }
    printf("%lld\n", ans);
  }
}
