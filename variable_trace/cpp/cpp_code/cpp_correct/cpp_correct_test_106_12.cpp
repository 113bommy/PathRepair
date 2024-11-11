#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int M = 2e5 + 5;
const long long mod = 1e9 + 7;
double eps = 1e-8;
inline long long read() {
  long long X = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    X = (X << 1) + (X << 3) + ch - '0';
    ch = getchar();
  }
  if (flag) return X;
  return ~(X - 1);
}
long long n, m, k;
long long a[N];
void solvve() {
  n = read();
  for (int i(1); i <= n; ++i) printf("%d ", i + 1);
  puts("");
}
int main() {
  int _;
  _ = read();
  while (_--) {
    solvve();
  }
  return 0;
}
