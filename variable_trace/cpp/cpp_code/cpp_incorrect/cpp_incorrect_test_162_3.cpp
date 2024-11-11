#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int n;
bool check(int x) {
  for (int i = 1; i <= n; i++) b[i] = a[i], c[i] = 0;
  for (int i = n; i >= 3; i--) {
    if (b[i] + c[i] < x) return false;
    int now = x - c[i];
    if (now <= 0) {
      int res = b[i] / 3;
      b[i] -= res * 3;
      c[i - 2] += 2 * res;
      c[i - 1] += res;
    } else {
      int res = (b[i] - now) / 3;
      b[i] -= res * 3;
      c[i - 2] += 2 * res;
      c[i - 1] += res;
    }
  }
  if (b[1] + c[1] < x || b[2] + c[2] < x) return false;
  return true;
}
int main() {
  std::ios::sync_with_stdio(false);
  int _;
  cin >> _;
  while (_--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = 10;
    while (l <= r) {
      int mid = l + r >> 1;
      if (check(mid)) {
        l = mid + 1;
      } else
        r = mid - 1;
    }
    cout << r << '\n';
  }
}
