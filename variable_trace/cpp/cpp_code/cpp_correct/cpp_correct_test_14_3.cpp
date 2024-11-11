#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int tc, n, a[N], b[N];
struct R {
  int x, y, z;
};
vector<R> vp;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
      if (a[i] == b[i]) continue;
      for (int j = i + 1; j <= n; j++) {
        if (a[j] == b[i]) {
          vp.push_back({i, j, j - i});
          while (j > i) {
            swap(a[j - 1], a[j]);
            --j;
          }
          break;
        }
      }
    }
    cout << vp.size() << "\n";
    for (auto i : vp) cout << i.x << " " << i.y << " " << i.z << "\n";
    vp.clear();
  }
  return 0;
}
