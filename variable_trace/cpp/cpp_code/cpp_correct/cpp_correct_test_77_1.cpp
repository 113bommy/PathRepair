#include <bits/stdc++.h>
using namespace std;
namespace std {}
long long t, n, m;
bitset<4> s[1005][1005];
bool vis[1005][1005];
queue<long long> Q;
long long A[(long long)1e6 + 10], N;
void bfs(long long x, long long y) {
  queue<pair<long long, long long>> q;
  long long cnt = 1;
  q.push({x, y});
  vis[x][y] = 1;
  while (q.size()) {
    long long a = q.front().first, b = q.front().second;
    q.pop();
    if (a - 1 >= 0 && !vis[a - 1][b] && !s[a - 1][b][1]) {
      cnt++;
      vis[a - 1][b] = 1;
      q.push({a - 1, b});
    }
    if (a + 1 < n && !vis[a + 1][b] && !s[a + 1][b][3]) {
      cnt++;
      vis[a + 1][b] = 1;
      q.push({a + 1, b});
    }
    if (b - 1 >= 0 && !vis[a][b - 1] && !s[a][b - 1][2]) {
      cnt++;
      vis[a][b - 1] = 1;
      q.push({a, b - 1});
    }
    if (b + 1 < m && !vis[a][b + 1] && !s[a][b + 1][0]) {
      cnt++;
      vis[a][b + 1] = 1;
      q.push({a, b + 1});
    }
  }
  A[N] = cnt;
  N++;
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < n; ++i)
    for (long long j = 0; j < m; ++j) {
      long long p;
      cin >> p;
      s[i][j] = p;
    }
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      if (!vis[i][j]) {
        bfs(i, j);
      }
    }
  }
  sort(A, A + N, greater<long long>());
  for (long long i = 0; i < N; ++i) cout << A[i] << " ";
}
