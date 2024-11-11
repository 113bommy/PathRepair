#include <bits/stdc++.h>
using namespace std;
const int NR = 2e5 + 5;
int a[NR];
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
int cnt[40];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i <= 31; ++i) {
      for (int j = 1; j <= n; ++j) {
        if ((1 << i) & a[j]) ++cnt[i];
      }
    }
    int nw = a[0];
    for (int i = 1; i <= 31; ++i) nw = gcd(nw, cnt[i]);
    for (int i = 1; i <= n; ++i) {
      if (nw % i == 0) printf("%d ", i);
    }
    puts("");
  }
  return 0;
}
