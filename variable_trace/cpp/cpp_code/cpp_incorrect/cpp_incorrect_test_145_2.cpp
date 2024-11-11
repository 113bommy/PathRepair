#include <bits/stdc++.h>
using namespace std;
map<int, vector<int> > gridx, gridy;
map<pair<int, int>, int> mp;
int timer[200005];
bool vis[200005];
vector<pair<int, int> > vec;
int n, k;
void init() {
  gridx.clear();
  gridy.clear();
  mp.clear();
  vec.clear();
}
int dfs(int s) {
  vis[s] = 1;
  int x, y;
  tie(x, y) = vec[s];
  int tym = timer[s], t1;
  int idx = lower_bound(gridx[x].begin(), gridx[x].end(), y) - gridx[x].begin();
  if (idx + 1 < gridx[x].size()) {
    int y1 = gridx[x][idx + 1];
    int num = mp[{x, y1}];
    if (abs(y1 - y) <= k and vis[num] == 0) {
      t1 = dfs(num);
      tym = min(tym, t1);
    }
  }
  if (idx - 1 >= 0) {
    int y1 = gridx[x][idx - 1];
    int num = mp[{x, y1}];
    if (abs(y1 - y) <= k and vis[num] == 0) {
      t1 = dfs(num);
      tym = min(tym, t1);
    }
  }
  idx = lower_bound(gridy[y].begin(), gridy[y].end(), x) - gridy[y].begin();
  if (idx + 1 < gridy[y].size()) {
    int x1 = gridy[y][idx + 1];
    int num = mp[{x1, y}];
    if (abs(x1 - x) <= k and vis[num] == 0) {
      t1 = dfs(num);
      tym = min(tym, t1);
    }
  }
  if (idx - 1 >= 0) {
    int x1 = gridy[y][idx - 1];
    int num = mp[{x1, y}];
    if (abs(x1 - x) <= k and vis[num] == 0) {
      t1 = dfs(num);
      tym = min(tym, t1);
    }
  }
  return tym;
}
void I_m_Beast() {
  init();
  int x, y;
  cin >> n >> k;
  vec.push_back({0, 0});
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    vec.push_back({x, y});
    gridx[x].push_back(y);
    gridy[y].push_back(x);
    mp[{x, y}] = i + 1;
    cin >> timer[i + 1];
  }
  for (auto &it : gridx) {
    int num = it.first;
    sort(gridx[num].begin(), gridx[num].end());
  }
  for (auto &it : gridy) {
    int num = it.first;
    sort(gridy[num].begin(), gridy[num].end());
  }
  set<int> time;
  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      int tym = dfs(i);
      time.insert(tym);
    }
  }
  int curTime = -1;
  while (time.size()) {
    auto it = time.end();
    it--;
    if (*it <= curTime) break;
    curTime++;
    time.erase(it);
  }
  cout << curTime << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    I_m_Beast();
  }
  return 0;
}
