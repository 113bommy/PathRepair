#include <bits/stdc++.h>
using namespace std;
bool adj[50][50];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    if (u <= 48 && v <= 48) adj[u][v] = adj[v][u] = 1;
  }
  for (int i = 1; i <= min(48, n); i++)
    for (int j = i + 1; j <= min(48, n); j++)
      for (int k = j + 1; k <= min(48, n); k++)
        for (int l = k + 1; l <= min(48, n); l++)
          for (int o = l + 1; o <= min(48, n); o++)
            if ((adj[i][j] && adj[i][k] && adj[i][l] && adj[i][o] &&
                 adj[j][k] && adj[j][l] && adj[j][o] && adj[k][l] &&
                 adj[k][o] && adj[l][o]) ||
                (!adj[i][j] && !adj[i][k] && !adj[i][l] && !adj[i][o] &&
                 !adj[j][k] && !adj[i][j] && !adj[i][k] && !adj[i][l] &&
                 !adj[i][o] && !adj[j][k])) {
              cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << o;
              return 0;
            }
  cout << -1;
  return 0;
}
