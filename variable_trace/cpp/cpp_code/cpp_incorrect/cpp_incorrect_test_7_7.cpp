#include <bits/stdc++.h>
using namespace std;
inline void pisz(int n) { printf("%d\n", n); }
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, -1, 0, 1};
const int drr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dcc[8] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int i = 0; i < ((int)((t).size())); i++) s << t[i] << " ";
  return s;
}
class UnionFind {
 private:
  vector<int> rank, p;

 public:
  UnionFind(int n) {
    for (int i = 0; i < n; i++) p.push_back(i);
    rank.assign(n, 0);
  }
  int findSet(int s) { return (p[s] == s) ? s : (p[s] = findSet(p[s])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;
    int x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y])
      p[y] = x;
    else {
      p[x] = y;
      if (rank[x] == rank[y]) rank[y]++;
    }
  }
};
bool fcomp(double A, double B) {
  double EPSILON = numeric_limits<double>::epsilon();
  double diff = A - B;
  return fabs(diff) < EPSILON;
}
double x_y(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
const int K = 26;
struct Vertex {
  int next[K];
  bool terminal = false;
  int terminal_idx = -1;
  int p = -1;
  char pch;
  int depth = 0;
  int link = 0;
  int next_terminal = 0;
  Vertex(int p, char ch, int depth) : p(p), pch(ch), depth(depth) {
    for (int i = 0; i < K; i++) next[i] = 0;
  }
};
vector<Vertex> t(1, {-1, '$', 0});
void add_string(std::string const& s, int idx) {
  int v = 0;
  for (char ch : s) {
    int c = ch - '0';
    if (!t[v].next[c]) {
      t[v].next[c] = t.size();
      t.emplace_back(v, ch, t[v].depth + 1);
    }
    v = t[v].next[c];
  }
  t[v].terminal = true;
  t[v].terminal_idx = idx;
}
vector<Vertex> tmp = t;
void push_links() {
  std::queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int v = q.front();
    auto& cur = t[v];
    auto& link = t[cur.link];
    q.pop();
    cur.next_terminal = link.terminal ? cur.link : link.next_terminal;
    for (int c = 0; c < K; c++) {
      if (cur.next[c]) {
        t[cur.next[c]].link = v ? link.next[c] : 0;
        q.push(cur.next[c]);
      } else {
        cur.next[c] = link.next[c];
      }
    }
  }
}
int transition(int idx, char c) { return t[idx].next[c - '0']; }
Vertex const& getInfo(int idx) { return t[idx]; }
short dp[510][510][570];
int n, m;
string s;
short rec(int id, int sid, int lft) {
  if (lft < 0) return 1000;
  if (id == n) {
    if (tmp[sid].terminal) lft--;
    if (lft == 0) return 0;
    return 1000;
  }
  short &ret = dp[id][sid][lft], res = 1000;
  if (ret != -1) return ret;
  int d = s[id] - '0';
  d ^= 1;
  if (tmp[sid].next[s[id] - '0']) {
    int c = lft, u = tmp[sid].next[s[id] - '0'];
    res = min(res, rec(id + 1, tmp[sid].next[s[id] - '0'], c));
    if (s[id] == '0') {
      res = min(res, short(1 + rec(id + 1, transition(sid, '1'), c)));
    } else {
      res = min(res, short(1 + rec(id + 1, transition(sid, '0'), c)));
    }
  } else {
    int c = lft;
    if (tmp[sid].terminal) c = lft - 1;
    res = min(res, rec(id + 1, transition(sid, s[id]), c));
    if (s[id] == '0') {
      res = min(res, short(1 + rec(id + 1, transition(sid, '1'), c)));
    } else {
      res = min(res, short(1 + rec(id + 1, transition(sid, '0'), c)));
    }
  }
  return ret = res;
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d%d", &n, &m);
  string s2;
  cin >> s >> s2;
  add_string(s2, 0);
  tmp = t;
  push_links();
  for (int i = 0; i < n - m + 3; i++) {
    int ans = rec(0, 0, i);
    if (ans > 900) ans = -1;
    cout << ans << " ";
  }
  return 0;
}
