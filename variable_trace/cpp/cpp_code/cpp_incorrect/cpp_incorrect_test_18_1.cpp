#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int INF = 10000000;
void work() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n, 0);
  vector<int> st(n, false);
  for (int i = 1; i <= n; i++) cin >> a[i - 1];
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (!st[i]) {
      st[i] = true;
      int v = i;
      vector<int> ans;
      ans.push_back(v);
      while (1) {
        int w = (v + d) % n;
        if (st[w]) break;
        st[w] = true;
        ans.push_back(w);
        v = w;
      }
      int cnt = ans.size();
      vector<int> p;
      for (int j = 0; j < cnt; j++) {
        if (a[ans[j]] == 0) p.push_back(j);
      }
      int cnt2 = p.size();
      if (p.empty()) {
        res = INF;
      } else {
        for (int j = 0; j < cnt2 - 1; j++) {
          res = max(res, p[i + 1] - p[i] - 1);
        }
        res = max(res, p[0] - p[cnt2 - 1] + cnt - 1);
      }
    }
  }
  if (res == INF) {
    cout << "-1\n";
  } else
    cout << res << "\n";
}
int main() {
  int T;
  scanf("%d", &T);
  for (int ca = 1; ca <= T; ++ca) {
    work();
  }
  return 0;
}
