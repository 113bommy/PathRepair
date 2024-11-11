#include <bits/stdc++.h>
const int N = 300300;
const int M = 333;
using namespace std;
int n;
int q;
int k;
int a[N];
int t[N][20];
int L[N];
int get_min(int l, int r) {
  int g = L[r - l + 1];
  return min(t[l][g], t[r - (1 << g) + 1][g]);
}
long long res[N];
vector<pair<int, int>> qu[N];
vector<pair<int, int>> c[M];
vector<pair<long long, int>> s[M];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> q >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    t[i][0] = a[i];
  }
  for (int i = 2; i < N; i++) {
    L[i] = L[i / 2] + 1;
  }
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= n; j++) {
      if (j + (1 << i) - 1 > n) {
        break;
      }
      t[j][i] = min(t[j][i - 1], t[j + (1 << i - 1)][i - 1]);
    }
  }
  if (k >= M) {
    for (int i = 1; i <= q; i++) {
      int l, r, j;
      cin >> l >> r;
      j = l;
      long long res = 0;
      while (j <= r) {
        res += get_min(l, j);
        j += k;
      }
      cout << res << "\n";
    }
    return 0;
  }
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    qu[l].push_back({(r - l) / k + 1, i});
  }
  for (int i = 0; i < k; i++) {
    c[i].push_back({0, 0});
    s[i].push_back({0, 0});
  }
  for (int i = n; i >= 1; i--) {
    int cur = i % k, X;
    for (int j = 0; j < k; j++) {
      X = (j == cur);
      while (c[j].empty() && a[i] <= c[j].back().first) {
        X += c[j].back().second;
        s[j].pop_back();
        c[j].pop_back();
      }
      if (X > 0) {
        c[j].push_back({a[i], X});
        s[j].push_back(
            {s[j].back().first + 1ll * a[i] * X, s[j].back().second + X});
      }
    }
    for (auto p : qu[i]) {
      int l = 0, r = s[cur].size() - 1;
      while (l < r) {
        int m = (l + r) / 2;
        if (s[cur].back().second - s[cur][m].second >= p.first) {
          l = m + 1;
        } else {
          r = m;
        }
      }
      res[p.second] += s[cur].back().first - s[cur][l].first;
      res[p.second] += (p.first - (s[cur].back().second - s[cur][l].second)) *
                       1ll * c[cur][l].first;
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << res[i] << "\n";
  }
}
