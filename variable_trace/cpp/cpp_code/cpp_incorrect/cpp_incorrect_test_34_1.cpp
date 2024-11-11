#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
vector<int> g[10010];
int r[10010];
bool ans[10010];
const int M = 1 << 13 - 1;
int main() {
  int n = read();
  ans[0] = 1;
  for (register int i = 0; i <= M; ++i) g[i].push_back(0), r[i] = M;
  while (n--) {
    int x = read();
    for (int y : g[x]) {
      int to = x ^ y;
      ans[to] = 1;
      for (register int i = x + 1; i <= r[to]; ++i) g[i].push_back(to);
      r[to] = min(r[to], x);
    }
    g[x] = {};
  }
  int k = 0;
  for (register int i = 0; i <= M; ++i) k += ans[i];
  printf("%d\n", k);
  for (register int i = 0; i <= M; ++i)
    if (ans[i]) printf("%d ", i);
  return 0;
}
