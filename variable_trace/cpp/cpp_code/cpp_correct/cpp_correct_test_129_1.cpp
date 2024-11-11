#include <bits/stdc++.h>
using namespace std;
inline void intxt() {}
inline void read(int &x) {
  int f = 1;
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
inline void read(long long &x) {
  long long f = 1;
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
const long long mod = 998244353;
const int N = 4e5 + 5;
const int M = 1e6 + 5;
int n, m, k;
int a[N];
multiset<int> cup;
int main() {
  intxt();
  int casen;
  scanf("%d", &casen);
  for (int LP = 1; LP <= casen; ++LP) {
    cin >> n;
    cup.clear();
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      cup.insert(a[i]);
    }
    int ans = 0;
    for (int i = n; i >= 1; i--) {
      if (cup.count(i) >= 1) {
        auto x = cup.lower_bound(i);
        cup.erase(x);
      } else {
        auto x = cup.upper_bound(i * 2);
        if (x == cup.end()) {
          ans = -1;
          break;
        }
        cup.erase(x);
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
