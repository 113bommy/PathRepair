#include <bits/stdc++.h>
using namespace std;
inline void out(int *a, int l, int r) {
  for (int i = l; i <= r; ++i) printf("%d ", *(a + i));
  puts("");
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
long long pw[50];
signed main() {
  int n = read(), k = read(), c = 0, t = n;
  while (t) {
    t /= k;
    c++;
  }
  pw[0] = 1;
  for (int i = 1; i <= c + 1; ++i) pw[i] = pw[i - 1] * k;
  cout << c << endl;
  for (int i = 0; i <= n - 1; ++i)
    for (int j = i + 1; j <= n - 1; ++j) {
      for (int w = 1; w <= c; ++w)
        if (i / pw[w] == j / pw[w]) {
          printf("%d ", w);
          break;
        }
    }
  return 0;
}
