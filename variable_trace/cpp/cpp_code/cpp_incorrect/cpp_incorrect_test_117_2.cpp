#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const double eps = 1e-8;
const long long mod = 998244353;
const long long MOD = 998244353;
const int maxn = 500010;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int sx, sy;
int T;
int N, M;
vector<vector<char>> field;
vector<vector<bool>> vis;
bool Check(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx >= 0 && nx < N && ny >= 0 && ny < M && field[nx][ny] == '.') cnt++;
  }
  return cnt <= 1;
}
void dfs(int x, int y) {
  vis[x][y] = true;
  if (field[x][y] == '.') field[x][y] = '+';
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx >= 0 && nx < N && ny >= 0 && ny < M && !vis[nx][ny] &&
        field[nx][ny] != '#' && Check(nx, ny))
      dfs(nx, ny);
  }
}
void solve() {
  dfs(sx, sy);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) cout << field[i][j];
    putchar('\n');
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    field.clear();
    vis.clear();
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
      vector<char> tmp;
      vector<bool> a;
      char ch;
      for (int j = 0; j < M; j++) {
        cin >> ch;
        if (ch == 'L') sx = i, sy = j;
        tmp.push_back(ch);
        a.push_back(false);
      }
      field.push_back(tmp);
      vis.push_back(a);
    }
    solve();
  }
  return 0;
}
