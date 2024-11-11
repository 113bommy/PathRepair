#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
void cincout() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(15);
}
pair<long long, long long> binarySearch(long long l, long long r, long long pr,
                                        long long x) {
  if (r >= l) {
    long long mid = l + (r - l) / 2;
    long long ans = (r) * (r + 1) / 2;
    cout << ans << "  r =" << r << endl;
    if (ans == x) return {l, r};
    if (ans > x) return binarySearch(l, mid - 1, r, x);
    return binarySearch(l, r + mid, r, x);
  }
  return {-1, -1};
}
set<int> parent;
vector<vector<pair<int, int> > > v(200005);
vector<int> d;
int N = 2000005;
int M = 2000005;
vector<int> mem(2000005);
vector<bool> visited(2000005);
vector<bool> imposter(2000005);
vector<bool> recStack(2000005);
set<int> second;
queue<int> q;
void dfsParent(int node) {
  visited[node] = 1;
  for (auto i : v[node]) {
    parent.erase(i.first);
    if (!visited[i.first]) {
      dfsParent(i.first);
    }
  }
}
void getparents() {
  for (int i = 1; i <= N; i++) parent.insert(i);
  for (int i = 1; i <= N; i++) {
    dfsParent(i);
  }
  if (parent.size() == 0) parent.insert(1);
}
bool ans = true;
int coun[2];
void dfs(int node) {
  coun[imposter[node]]++;
  visited[node] = 1;
  for (auto i : v[node]) {
    auto first = imposter[node] ^ i.second;
    if (!visited[i.first]) {
      imposter[i.first] = first;
      dfs(i.first);
    } else if (first != imposter[i.first]) {
      ans = false;
      return;
    }
  }
}
void solve() {
  getparents();
  for (int i = 1; i <= N; i++) {
    visited[i] = 0;
  }
  int maxx = 0;
  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {
      dfs(i);
      maxx += max(coun[0], coun[1]);
      coun[0] = coun[1] = 0;
    }
  }
  if (!ans) {
    cout << -1 << endl;
  } else {
    if (M == 0)
      cout << N << endl;
    else
      cout << maxx << endl;
  }
}
int main() {
  cincout();
  long long t = 1;
  cin >> t;
  int i = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    N = n;
    M = m;
    string ss;
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      string second;
      cin >> second;
      bool first = second[0] == 'c' ? 0 : 1;
      v[a].push_back({b, first});
      v[b].push_back({a, first});
    }
    solve();
    parent.clear();
    ans = true;
    coun[0] = coun[1] = 0;
    for (int i = 1; i <= n; i++) {
      visited[i] = 0;
      imposter[i] = 0;
      v[i].clear();
    }
  }
  return 0;
}
