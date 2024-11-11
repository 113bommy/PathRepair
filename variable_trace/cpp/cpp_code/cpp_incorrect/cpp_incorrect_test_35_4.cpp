#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return flag ? x : ~(x - 1);
}
inline void write(long long x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const long long N = 1e6 + 10;
long long n, ans, a[N];
long long prime[N], mp[N], cnt;
long long stk[N], top, pre[N], w[N];
bool is_prime[N];
vector<long long> vec[N];
inline void sieve(long long x) {
  for (long long i = 2; i <= x; i++) {
    if (!is_prime[i]) prime[++cnt] = mp[i] = i;
    for (long long j = 1; prime[j] <= x / i; j++) {
      is_prime[i * prime[j]] = true;
      mp[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) break;
    }
  }
}
signed main() {
  sieve(1000000);
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= n; i++) {
    char ch = getchar();
    while (ch != '*' && ch != '/') ch = getchar();
    if (ch == '*') {
      while (a[i] > 1) {
        long long p = mp[a[i]];
        vec[p].push_back(i);
        a[i] /= p;
      }
      pre[i] = i;
    } else {
      pre[i] = i;
      while (a[i] > 1) {
        long long p = mp[a[i]];
        if (vec[p].empty())
          pre[i] = -1;
        else
          pre[i] = min(pre[i], vec[p].back()), vec[p].pop_back();
        a[i] /= p;
      }
    }
  }
  for (long long i = n; i >= 1; i--) {
    long long nw = 1;
    while (top && pre[i] < stk[top]) nw += w[top], top--;
    stk[++top] = pre[i], w[top] = nw;
    if (i == pre[i]) ans += nw;
  }
  write(ans), putchar('\n');
  return 0;
}
