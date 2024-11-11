#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = 1e5 + 29;
int a[N], b[N];
int c[N];
int n;
int cnt;
void add(int x) {
  while (x <= n) {
    c[x] += 1;
    x += x & -x;
  }
}
int get(int x) {
  int ans = 0;
  while (x) {
    ans += c[x];
    x -= x & -x;
  }
  return ans;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    c[i] = 0;
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  cnt = unique(b + 1, b + 1 + n) - b - 1;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int p = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    int x = get(p - 1);
    int y = get(n) - get(p);
    ans += min(x, y);
    add(p);
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
