#include <bits/stdc++.h>
using namespace std;
int k;
map<int, vector<int>> mx;
map<int, vector<int>> my;
map<pair<int, int>, bool> used;
map<pair<int, int>, int> time_of;
int dfs(int x, int y) {
  used[{x, y}] = true;
  int _min_ = time_of[{x, y}];
  auto i = lower_bound(mx[x].begin(), mx[x].end(), y);
  auto j = lower_bound(my[y].begin(), my[y].end(), x);
  if (++i != mx[x].end() && !used[{x, *i}] && abs(*i - y) <= k) {
    _min_ = min(_min_, dfs(x, *i));
  }
  --i;
  if (i != mx[x].begin() && !used[{x, *(--i)}] && abs(*i - y) <= k) {
    _min_ = min(_min_, dfs(x, *i));
  }
  if (++j != my[y].end() && !used[{*j, y}] && abs(*j - x) <= k) {
    _min_ = min(_min_, dfs(*j, y));
  }
  --j;
  if (j != my[y].begin() && !used[{*(--j), y}] && abs(*j - x) <= k) {
    _min_ = min(_min_, dfs(*j, y));
  }
  return _min_;
}
void solve() {
  mx.clear();
  my.clear();
  used.clear();
  int n;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  int x, y, timer;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y >> timer;
    a[i] = {x, y};
    time_of[{x, y}] = timer;
    mx[x].push_back(y);
    my[y].push_back(x);
  }
  vector<int> res;
  for (auto now : mx) {
    sort(mx[now.first].begin(), mx[now.first].end());
  }
  for (auto now : my) {
    sort(my[now.first].begin(), my[now.first].end());
  }
  for (auto now : a) {
    if (!used[now]) {
      res.push_back(dfs(now.first, now.second));
    }
  }
  sort(res.begin(), res.end(), greater<int>());
  deque<int> times_;
  for (int i = 0; i < res.size(); i++) {
    times_.push_back(res[i]);
  }
  int timeCount = 0;
  while (!times_.empty()) {
    if (times_.front() > timeCount) times_.pop_front();
    while (!times_.empty() || times_.back() == timeCount) {
      times_.pop_back();
    }
    timeCount++;
  }
  cout << timeCount - 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tests;
  cin >> tests;
  for (int tt = 0; tt < int(tests); tt++) {
    solve();
  }
}
