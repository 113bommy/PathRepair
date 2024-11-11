#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
    vector<int> ord(n);
    for (int i = 0; i < n; i++) ord[i] = i;
    sort(ord.begin(), ord.end(),
         [&a](int x, int y) { return a[x][0] > a[y][0]; });
    vector<vector<int>> maxl(n, vector<int>(m, -INF));
    vector<vector<int>> minr(n, vector<int>(m, INF));
    for (int i = n - 1; i >= 0; i--)
      for (int j = 0; j < m; j++) {
        maxl[i][j] = a[ord[i]][j];
        if (i < n - 1) maxl[i][j] = max(maxl[i][j], maxl[i + 1][j]);
        if (j > 0) maxl[i][j] = max(maxl[i][j], maxl[i][j - 1]);
      }
    for (int i = n - 1; i >= 0; i--)
      for (int j = m - 1; j >= 0; j--) {
        minr[i][j] = a[ord[i]][j];
        if (i < n - 1) minr[i][j] = min(minr[i][j], minr[i + 1][j]);
        if (j < m - 1) minr[i][j] = min(minr[i][j], minr[i][j + 1]);
      }
    vector<int> minl(m, INF), maxr(m, -INF);
    pair<int, int> ans = {-1, -1};
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m; j++) {
        minl[j] = min(minl[j], a[ord[i]][j]);
        if (j > 0) minl[j] = min(minl[j], minl[j - 1]);
      }
      for (int j = m - 1; j >= 0; j--) {
        maxr[j] = max(maxr[j], a[ord[i]][j]);
        if (j < m - 1) maxr[j] = max(maxr[j], maxr[j + 1]);
      }
      for (int j = 0; j < m - 1; j++)
        if (minl[j] > maxl[i + 1][j] && maxr[j + 1] < minr[i + 1][j + 1])
          ans = {i, j};
    }
    if (ans.first == -1) {
      puts("NO");
      continue;
    }
    puts("YES");
    string res(n, ' ');
    for (int i = 0; i < n; i++) res[ord[i]] = i <= ans.first ? 'R' : 'B';
    printf("%s %d\n", res.c_str(), ans.second + 1);
  }
}
