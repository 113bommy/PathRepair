#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 100;
const int INF = 0x7fffffff;
const long long mod = 1e9 + 7;
const long long mod1 = 998244353;
const long long base = 137;
const double Pi = acos(-1.0);
const int G = 3;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long s, n, k;
    scanf("%lld%lld%lld", &s, &n, &k);
    if (s < k) {
      puts("NO");
      continue;
    }
    if (s == k) {
      puts("YES");
      continue;
    }
    long long p = 0;
    p += (s % k) * (((s / k + 1) + 1) / 2);
    p += (k - s % k - 1) * ((s / k + 1) / 2);
    long long q = s / k;
    q--;
    p += (q + 1) / 2;
    if (p >= n) {
      puts("NO");
    } else
      puts("YES");
  }
}
