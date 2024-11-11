#include <bits/stdc++.h>
using namespace std;
int findType(vector<vector<char>> &grid, int i, int j) {
  int n = grid.size(), m = grid[0].size();
  if (i < 0 || i >= n) return 2;
  if (j < 0 || j >= m) return 2;
  if (grid[i][j] == '#') return 2;
  if (grid[i][j] == '+' || grid[i][j] == 'L') return 1;
  return 0;
}
void calc(vector<vector<char>> &grid, int i, int j, int &win, int &lose) {
  int t = findType(grid, i, j);
  if (t == 1)
    win++;
  else if (t == 0)
    lose++;
}
void dfs(vector<vector<char>> &grid, int i, int j) {
  int n = grid.size(), m = grid[0].size();
  if (i < 0 || i >= n) return;
  if (j < 0 || j >= m) return;
  if (grid[i][j] == '#') return;
  if (grid[i][j] == '+') return;
  if (grid[i][j] == 'L') {
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
    return;
  }
  int lose = 0, win = 0;
  calc(grid, i + 1, j, win, lose);
  calc(grid, i - 1, j, win, lose);
  calc(grid, i, j - 1, win, lose);
  calc(grid, i, j + 1, win, lose);
  if (lose <= 1 && win) {
    grid[i][j] = '+';
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    int r, c;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
        if (grid[i][j] == 'L') {
          r = i;
          c = j;
        }
      }
    }
    dfs(grid, r, c);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << grid[i][j];
      cout << "\n";
    }
  }
}
