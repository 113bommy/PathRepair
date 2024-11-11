#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int LOG = 30;
vector<char> a[maxn];
vector<int> dp[maxn];
int st[maxn][LOG];
int bin[LOG];
int mlg[maxn];
int n, m, q;
void init(int);
int query(int, int);
void print() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << dp[i][j] + 1 << " ";
    }
    cout << '\n';
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    dp[i].resize(m);
    string s;
    cin >> s;
    for (int j = 0; j < s.length(); j++) {
      a[i].push_back(s[j]);
    }
  }
  for (int i = 0; i < n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i < m; i++) {
    dp[0][i] = 0;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i - 1][j] == 'X' && a[i][j - 1] == 'X')
        dp[i][j] = j;
      else if (a[i - 1][j] == 'X')
        dp[i][j] = dp[i][j - 1];
      else if (a[i][j - 1] == 'X')
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]);
    }
  }
  for (int j = 0; j < m; j++) {
    int tmp = -1;
    for (int i = 0; i < n; i++) {
      tmp = max(dp[i][j], tmp);
    }
    st[j][0] = tmp;
  }
  init(m);
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l == r)
      cout << "YES\n";
    else {
      int maxx = query(l - 1, r - 1);
      if (maxx > l - 1)
        cout << "NO\n";
      else
        cout << "YES\n";
    }
  }
}
void init(int n) {
  mlg[0] = -1;
  for (int i = 1; i <= n; i++) {
    mlg[i] = mlg[i / 2] + 1;
  }
  bin[0] = 1;
  for (int i = 1; i < LOG; i++) {
    bin[i] = bin[i - 1] * 2;
  }
  for (int j = 1; j < mlg[n]; j++) {
    for (int i = 0; i + bin[j] - 1 < n; i++) {
      st[i][j] = max(st[i][j - 1], st[i + bin[j - 1]][j - 1]);
    }
  }
}
int query(int x, int y) {
  int t = mlg[y - x + 1];
  return max(st[x][t], st[y - bin[t] + 1][t]);
}
