#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
const int MAXN = 2e5 + 100;
const int LOGN = 18;
const int MAXT = 300;
const int MOD = (int)1e9 + 7;
void clear() {}
int sum(int a, int b) { return (a + b) % MOD; }
int sub(int a, int b) { return (a + MOD - b) % MOD; }
int mult(int a, int b) { return ((long long)a * b) % MOD; }
void gen_tests() {}
struct FenwickTree {
  unordered_map<int, int> values;
  unordered_map<int, int> sub_values;
  int min_value = (int)1e9;
  int n;
  void Initialize(int sz) { n = sz; }
  void Add(int i, int val) {
    min_value = min(i, min_value);
    sub_values[i] = sum(val, sub_values[i]);
    for (; i < n; i = i | (i + 1)) values[i] = sum(values[i], val);
  }
  int Sum(int i) {
    int d = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      if (values.count(i)) d = sum(d, values[i]);
    }
    return d;
  }
  int Sum(int l, int r) { return sub(Sum(r), Sum(l - 1)); }
};
vector<pair<int, int> > g[MAXN];
int colors[MAXN];
int h[MAXN];
int base_h[MAXN];
FenwickTree trees[MAXN];
FenwickTree indexes_trees[MAXN];
int parents[MAXN];
int get_parent(int i) {
  return parents[i] == i ? i : parents[i] = get_parent(parents[i]);
}
int get_distance(int v, int to, int max_tickets, int base_distance,
                 int base_h) {
  int result = 0;
  v = get_parent(v);
  to = get_parent(to);
  if (trees[v].sub_values.size() < trees[to].sub_values.size()) swap(v, to);
  for (auto u : trees[to].sub_values) {
    int last_tickets = max_tickets - (u.first - trees[to].min_value);
    if (last_tickets < 0) continue;
    int index_right_count = indexes_trees[to].sub_values[u.first];
    int sum_right = u.second;
    int index = min(trees[v].n - 1, last_tickets + trees[v].min_value);
    int index_left_count = indexes_trees[v].Sum(index);
    int sum_left = trees[v].Sum(index);
    result =
        sum(result, mult(sub(sum_right, mult(index_right_count, base_distance)),
                         index_left_count));
    result =
        sum(result, mult(sub(sum_left, mult(index_left_count, base_distance)),
                         index_right_count));
    result =
        sum(result, mult(index_left_count, mult(base_h, index_right_count)));
  }
  return result;
}
void merge(int v, int to) {
  v = get_parent(v);
  to = get_parent(to);
  if (trees[v].sub_values.size() > trees[to].sub_values.size()) swap(v, to);
  parents[v] = to;
  for (auto u : trees[v].sub_values) {
    trees[to].Add(u.first, u.second);
    indexes_trees[to].Add(u.first, indexes_trees[v].sub_values[u.first]);
  }
  trees[v].sub_values.clear();
  trees[v].values.clear();
  indexes_trees[v].values.clear();
  indexes_trees[v].sub_values.clear();
}
void dfs(int v, int prev_color, int p) {
  for (auto u : g[v]) {
    if (u.first == p) continue;
    h[u.first] = sum(h[v], h[u.first]);
    colors[u.first] = colors[v] + (prev_color != u.second ? 1 : 0);
    dfs(u.first, u.second, v);
  }
}
int response;
int base_tickets;
void dfs1(int v, int p) {
  indexes_trees[v].Add(colors[v], 1);
  trees[v].Add(colors[v], h[v]);
  vector<int> first_indexes;
  vector<int> second_indexes;
  for (auto u : g[v]) {
    if (u.first == p) continue;
    dfs1(u.first, v);
    if (u.second == 0)
      first_indexes.push_back(u.first);
    else
      second_indexes.push_back(u.first);
  }
  if (first_indexes.size() + second_indexes.size() == 0) return;
  for (int i = 1; i < first_indexes.size(); ++i) {
    response = sum(response, get_distance(first_indexes[0], first_indexes[i],
                                          base_tickets, h[v], base_h[v]));
    merge(first_indexes[0], first_indexes[i]);
  }
  for (int i = 1; i < second_indexes.size(); ++i) {
    response = sum(response, get_distance(second_indexes[0], second_indexes[i],
                                          base_tickets, h[v], base_h[v]));
    merge(second_indexes[0], second_indexes[i]);
  }
  if (first_indexes.size()) {
    int par_val = get_parent(first_indexes[0]);
    int m = min(trees[par_val].n - 1, trees[par_val].min_value + base_tickets);
    response = sum(
        response, sub(trees[par_val].Sum(m), mult(indexes_trees[par_val].Sum(m),
                                                  sub(h[v], base_h[v]))));
  }
  if (second_indexes.size()) {
    int par_val = get_parent(second_indexes[0]);
    int m = min(trees[par_val].n - 1, trees[par_val].min_value + base_tickets);
    response = sum(
        response, sub(trees[par_val].Sum(m), mult(indexes_trees[par_val].Sum(m),
                                                  sub(h[v], base_h[v]))));
  }
  if (first_indexes.size() && second_indexes.size()) {
    response = sum(response, get_distance(first_indexes[0], second_indexes[0],
                                          base_tickets - 1, h[v], base_h[v]));
    merge(first_indexes[0], second_indexes[0]);
  }
  int par_val = first_indexes.size() ? first_indexes[0] : second_indexes[0];
  par_val = get_parent(par_val);
  merge(v, par_val);
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
    response = sum(response, h[i]);
    base_h[i] = h[i];
  }
  base_tickets = m;
  for (int i = 0; i + 1 < n; ++i) {
    int v, to, e;
    cin >> v >> to >> e;
    v--;
    to--;
    g[v].push_back({to, e});
    g[to].push_back({v, e});
  }
  dfs(0, -1, 0);
  for (int i = 0; i < n; ++i) {
    parents[i] = i;
    trees[i].Initialize(n);
    indexes_trees[i].Initialize(n);
  }
  dfs1(0, 0);
  cout << response << '\n';
}
void precalc() {}
void multisolve() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  precalc();
  solve();
  return 0;
}
