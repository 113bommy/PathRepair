#include <bits/stdc++.h>
using namespace std;
void call() {
  int n;
  cin >> n;
  vector<vector<int>> arr(2, vector<int>(n));
  vector<vector<bool>> visited(2, vector<bool>(n, false));
  string s1;
  cin >> s1;
  string s2;
  cin >> s2;
  for (int j = 0; j < n; ++j) {
    arr[0][j] = s1[j] - '0';
  }
  for (int j = 0; j < n; ++j) {
    arr[1][j] = s2[j] - '0';
  }
  queue<pair<int, int>> q;
  q.push({0, 0});
  visited[0][0] = 1;
  while (q.empty() == false) {
    int k = q.size();
    while (k--) {
      pair<int, int> curr = q.front();
      int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
      int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
      int x = curr.first;
      int y = curr.second;
      q.pop();
      for (int i = 0; i < 8; ++i) {
        if (x + dx[i] >= 0 and x + dx[i] < 2 and y + dy[i] >= 0 and
            y + dy[i] < n and arr[x + dx[i]][y + dy[i]] == 0 and
            visited[x + dx[i]][y + dy[i]] == 0) {
          visited[x + dx[i]][y + dy[i]] = 1;
          q.push({x + dx[i], y + dy[i]});
        }
      }
    }
  }
  if (visited[1][n - 1]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) call();
}
