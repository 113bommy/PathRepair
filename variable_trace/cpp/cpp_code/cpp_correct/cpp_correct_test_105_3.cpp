#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, a[N], b[N], m[N], cur_a[N], cur_b[N], mn[N], mx[N];
int solve(vector<int> &v) {
  int res = 0;
  vector<pair<pair<int, int>, int> > seg;
  for (auto idx : v) {
    seg.push_back({{mx[idx], mn[idx]}, idx});
  }
  sort(seg.begin(), seg.end());
  int mxx = -1;
  for (auto it : seg) {
    int l = it.first.second, r = it.first.first, idx = it.second;
    if (l > mxx) mxx = r, res++;
    mn[idx] = mxx;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    long long sum = 0;
    map<long long, vector<int> > mp;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i] >> m[i];
      long long tmp_m = m[i];
      long long tmp = min(tmp_m, a[i]);
      cur_a[i] = a[i] - tmp;
      tmp_m -= tmp;
      tmp = min(tmp_m, b[i]);
      cur_b[i] = b[i] - tmp;
      mn[i] = cur_a[i], mx[i] = mn[i] + min({a[i] - cur_a[i], cur_b[i], m[i]});
      mp[a[i] + b[i] - m[i]].push_back(i);
    }
    int ans = 0;
    for (auto it : mp) {
      ans += solve(it.second);
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; i++) {
      int diff = mn[i] - cur_a[i];
      cur_a[i] += diff, cur_b[i] -= diff;
      cout << a[i] - cur_a[i] << ' ' << b[i] - cur_b[i] << '\n';
    }
  }
  return 0;
}
