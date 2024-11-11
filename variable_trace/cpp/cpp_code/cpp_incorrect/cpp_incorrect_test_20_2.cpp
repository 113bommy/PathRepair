#include <bits/stdc++.h>
using namespace std;
using Vi = vector<int>;
using i64 = long long;
using ll = long long;
using Pi = pair<int, int>;
mt19937 mrand(time(0));
int rnd(int x) { return mrand() % x; }
const int N = 500005;
const int M = 40005;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    Vi que(m * 2);
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    vector<Vi> col(n, Vi(m));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        col[i][j] = (i == 0 ? 0 : col[i - 1][j]) + s[i][j] - '0';
    int ans = 1000000001;
    for (int i = 0; i < n; ++i)
      for (int j = i + 4; j < n; ++j) {
        Vi t, p;
        int tail = -1, head = 0, add = 0;
        for (int k = 0; k < m; ++k) {
          t.push_back(j - i - 1 - (col[j - 1][k] - col[i][k]));
          p.push_back((col[j - 1][k] - col[i][k]) + (s[i][k] == '0') +
                      (s[j][k] == '0'));
          if ((int)p.size() > 1) p[(int)p.size() - 1] += p[(int)p.size() - 2];
          if (k > 2) {
            int sum = t[k - 3] + p[k - 1] - p[k - 3];
            sum -= add;
            while (tail >= head && que[tail] >= sum) --tail;
            que[++tail] = sum;
            ans = min(ans, t[k] + sum + add);
            add += p[(int)p.size() - 1] - p[(int)p.size() - 2];
          }
        }
      }
    cout << ans << endl;
  }
  return 0;
}
