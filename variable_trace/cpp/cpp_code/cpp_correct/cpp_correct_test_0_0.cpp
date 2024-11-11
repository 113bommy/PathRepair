#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 1e5 + 5;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> in(n);
  for (auto& x : in) cin >> x;
  vector<int> order(n);
  iota(begin(order), end(order), 0);
  sort(begin(order), end(order), [&](int i, int j) {
    for (int k = 0; k < m; k++) {
      if (in[i][k] != in[j][k]) {
        if (k % 2 == 0) {
          return in[i][k] < in[j][k];
        } else {
          return in[i][k] > in[j][k];
        }
      }
    }
    return false;
  });
  for (int i : order) cout << i + 1 << "\n";
}
