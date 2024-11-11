#include <bits/stdc++.h>
using namespace std;
int col[1010][1010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int tmp = n, cnt = 0;
  while (tmp) {
    ++cnt;
    tmp /= k;
  }
  cout << cnt << '\n';
  int i, j;
  for (i = 1; i <= n; ++i) {
    for (j = i + 1; j <= n; ++j) {
      int tmpi = i - 1, tmpj = j - 1;
      cnt = 0;
      while (tmpi != tmpj) {
        tmpi /= k;
        tmpj /= k;
        ++cnt;
      }
      cout << cnt << ' ';
    }
  }
  cout << '\n';
  return 0;
}
