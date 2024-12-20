#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    queue<pair<int, int>> q;
    vector<vector<int>> bad_deg(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '#' || a[i][j] == 'L') {
          continue;
        }
        int good_deg = 0;
        if (j < m - 1) {
          if (a[i][j + 1] == '.') {
            bad_deg[i][j]++;
          }
          if (a[i][j + 1] == 'L') {
            good_deg++;
          }
        }
        if (j > 0) {
          if (a[i][j - 1] == '.') {
            bad_deg[i][j]++;
          }
          if (a[i][j - 1] == 'L') {
            good_deg++;
          }
        }
        if (i < n - 1) {
          if (a[i + 1][j] == '.') {
            bad_deg[i][j]++;
          }
          if (a[i + 1][j] == 'L') {
            good_deg++;
          }
        }
        if (i > 0) {
          if (a[i - 1][j] == '.') {
            bad_deg[i][j]++;
          }
          if (a[i - 1][j] == 'L') {
            good_deg++;
          }
        }
        if (bad_deg[i][j] == 1 && good_deg == 1) {
          q.push({i, j});
        }
      }
    }
    vector<vector<bool>> used(n, vector<bool>(m));
    while (!q.empty()) {
      int i = q.front().first;
      int j = q.front().second;
      q.pop();
      used[i][j] = true;
      a[i][j] = '+';
      if (j < m - 1 && a[i][j + 1] == '.' && !used[i][j + 1]) {
        bad_deg[i][j + 1]--;
        if (bad_deg[i][j + 1] <= 1) {
          q.push({i, j + 1});
        }
      }
      if (j > 0 && a[i][j - 1] == '.' && !used[i][j - 1]) {
        bad_deg[i][j - 1]--;
        if (bad_deg[i][j - 1] <= 1) {
          q.push({i, j - 1});
        }
      }
      if (i < n - 1 && a[i + 1][j] == '.' && !used[i + 1][j]) {
        bad_deg[i + 1][j]--;
        if (bad_deg[i + 1][j] <= 1) {
          q.push({i + 1, j});
        }
      }
      if (i > 0 && a[i - 1][j] == '.' && !used[i - 1][j]) {
        bad_deg[i - 1][j]--;
        if (bad_deg[i - 1][j] <= 1) {
          q.push({i - 1, j});
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j];
      }
      cout << "\n";
    }
  }
}
