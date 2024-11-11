#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
using namespace std;
namespace ywy {
inline long long get() {
  long long n = 0;
  char c;
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9') break;
    if (c == '-') goto s;
  }
  n = c - '0';
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9')
      n = n * 10 + c - '0';
    else
      return (n);
  }
s:
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9')
      n = n * 10 - c + '0';
    else
      return (n);
  }
}
long long cn2(long long n) {
  if (n < 2) return 0;
  return n * (n - 1) / 2;
}
long long cn3(long long n) {
  if (n < 3) return 0;
  return n * (n - 1) * (n - 2) / 6;
}
void ywymain() {
  int n;
  double prob;
  scanf("%d", &n);
  scanf("%lf", &prob);
  for (int i = 0; i <= n; i++) {
    double n3 = cn3(n);
    double s = (i * cn2(n - i) / n3) / 2 + cn2(i) * (n - i) / n3 + cn3(i) / n3;
    if (s >= prob - 1e-7) {
      cout << i << endl;
      return;
    }
  }
  cout << 23 << endl;
}
}  // namespace ywy
signed main() {
  ywy::ywymain();
  return 0;
}
