#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int d[maxn];
unordered_map<int, int> mp;
struct node {
  int id;
  int va;
};
vector<node> vec;
bool cmp(node a, node b) { return a.va < b.va; }
bool vis[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    vec.clear();
    mp.clear();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      mp[x]++;
      vis[i] = 0;
      vec.push_back({i, x});
    }
    bool flag = false;
    for (auto i : mp) {
      if (i.second >= 2) {
        cout << "NO" << '\n';
        ;
        flag = true;
        break;
      }
    }
    if (flag) continue;
    sort(vec.begin(), vec.end(), cmp);
    for (int i = 0; i < n; i++) {
      d[vec[i].id] = i + 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      int to = i;
      vis[to] = true;
      to = d[to];
      int ta = 1;
      while (to != i) {
        vis[to] = true;
        ta++;
        to = d[to];
      }
      if (ta & 1)
        ;
      else
        cnt++;
    }
    cout << ((cnt & 1) ? "NO" : "YES") << '\n';
    ;
  }
  return 0;
}
