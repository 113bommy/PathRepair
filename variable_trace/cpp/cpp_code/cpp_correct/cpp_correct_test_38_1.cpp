#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const double eps = 1e-6;
int n, m;
vector<string> M;
namespace BIT {
int dat[maxn];
int lowbit(int x) { return x & (-x); }
void add(int i, int x) {
  while (i < maxn) {
    dat[i] += x;
    i += lowbit(i);
  }
}
int sum(int i) {
  int res = 0;
  while (i) {
    res += dat[i];
    i -= lowbit(i);
  }
  return res;
}
int sum(int l, int r) { return sum(r) - sum(l - 1); }
}  // namespace BIT
int main() {
  cin >> n >> m;
  M.resize(n + 1);
  M[0] = string(m + 1, '.');
  for (int i = 1; i <= n; i++) {
    M[i] += ".";
    string str;
    cin >> str;
    M[i] += str;
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (M[i - 1][j] == 'X' && M[i][j - 1] == 'X') {
        BIT::add(j, 1);
        break;
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (BIT::sum(l + 1, r) != 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
