#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, i, j, k, t;
  long long p;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld%lld", &n, &m, &k);
    if (m > (n - 1) * n / 2)
      printf("no\n");
    else if (m < n - 1)
      printf("no\n");
    else if (k > 3)
      printf("yes\n");
    else if (k == 2) {
      if (n == 1)
        printf("yes\n");
      else
        printf("no\n");
    } else if (k == 3) {
      if (m >= n * (n - 1) / 2)
        printf("yes\n");
      else
        printf("no\n");
    } else if (k == 1)
      printf("no\n");
  }
}
