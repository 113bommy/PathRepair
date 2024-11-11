#include <bits/stdc++.h>
using namespace std;
long long t, n;
inline long long read() {
  long long x = 0, f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') {
      f = -1;
    }
  } while (!(ch >= '0' && ch <= '9'));
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
signed main() {
  t = read();
  while (t--) {
    long long n = read();
    for (long long i = 2; i <= n; i++) {
      printf("%lld ", i);
    }
    printf("\n");
  }
  return 0;
}
