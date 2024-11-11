#include <bits/stdc++.h>
const long long INF = (long long)0x3f3f3f3f3f3f3f, MAX = 9e18, MIN = -9e18;
const double PI = acos(-1.0);
const double eps = 1e-6;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 100 + 10;
using namespace std;
int n, m, k;
int a[maxn];
int maxx[2][maxn], minn[2][maxn], sum[2][maxn];
void run_case() {
  cin >> n >> m;
  string s;
  cin >> s;
  s = " " + s;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j <= 1; j++) {
      maxx[j][i] = -inf;
      minn[j][i] = inf;
      sum[j][i] = 0;
    }
  }
  int x = 1, y = 1;
  long long ans = 0;
  for (int i = 1; i < s.size(); i++) {
    for (int j = 0; j <= 1; j++) {
      sum[j][i] = sum[j][i - 1];
    }
    if (s[i] == 'L')
      sum[0][i]--;
    else if (s[i] == 'R')
      sum[0][i]++;
    else if (s[i] == 'U')
      sum[1][i]++;
    else if (s[i] == 'D')
      sum[1][i]--;
    maxx[0][i] = max(maxx[0][i - 1], sum[0][i]);
    maxx[1][i] = max(maxx[1][i - 1], sum[1][i]);
    minn[0][i] = min(minn[0][i - 1], sum[0][i]);
    minn[1][i] = min(minn[1][i - 1], sum[1][i]);
    int l = 0, r = 0;
    if (minn[0][i] >= 0)
      l = maxx[0][i];
    else if (maxx[0][i] <= 0)
      l = abs(minn[0][i]);
    else
      l = maxx[0][i] - minn[0][i];
    if (minn[1][i] >= 0)
      r = maxx[1][i];
    else if (maxx[1][i] <= 0)
      r = abs(minn[1][i]);
    else
      r = maxx[1][i] - minn[1][i];
    if (l + 1 <= m && r + 1 <= n) {
      if (minn[0][i] >= 0)
        x = m - maxx[0][i];
      else if (maxx[0][i] <= 0)
        x = abs(minn[0][i]) + 1;
      else
        x = abs(minn[0][i]) + 1;
      if (minn[1][i] >= 0)
        y = n - maxx[1][i];
      else if (maxx[1][i] <= 0)
        y = abs(minn[1][i]) + 1;
      else
        y = abs(minn[1][i]) + 1;
    } else
      break;
  }
  cout << y << " " << x << "\n";
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int _ = 1;
  cin >> _;
  while (_--) {
    run_case();
  }
}
