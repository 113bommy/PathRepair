#include <bits/stdc++.h>
const int mod = 1000000007;
const int gmod = 3;
const int inf = 1039074182;
const double eps = 1e-9;
const double pi = 3.141592653589793238462643383279;
const long long llinf = 2LL * inf * inf;
template <typename T1, typename T2>
inline void chmin(T1 &x, T2 b) {
  if (b < x) x = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &x, T2 b) {
  if (b > x) x = b;
}
inline void chadd(int &x, int b) {
  x += b - mod;
  x += (x >> 31 & mod);
}
template <typename T1, typename T2>
inline void chadd(T1 &x, T2 b) {
  x += b;
  if (x >= mod) x -= mod;
}
template <typename T1, typename T2>
inline void chmul(T1 &x, T2 b) {
  x = 1LL * x * b % mod;
}
template <typename T1, typename T2>
inline void chmod(T1 &x, T2 b) {
  x %= b, x += b;
  if (x >= b) x -= b;
}
template <typename T>
inline T mabs(T x) {
  return (x < 0 ? -x : x);
}
using namespace std;
using namespace std;
template <typename T>
ostream &operator<<(ostream &cout, const vector<T> &vec) {
  cout << "{";
  for (int i = 0; i < (int)vec.size(); i++) {
    cout << vec[i];
    if (i != (int)vec.size() - 1) cout << ',';
  }
  cout << "}";
  return cout;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &cout, pair<T1, T2> p) {
  cout << "(" << p.first << ',' << p.second << ")";
  return cout;
}
template <typename T, typename T2>
ostream &operator<<(ostream &cout, set<T, T2> s) {
  vector<T> t;
  for (auto x : s) t.push_back(x);
  cout << t;
  return cout;
}
template <typename T, typename T2>
ostream &operator<<(ostream &cout, multiset<T, T2> s) {
  vector<T> t;
  for (auto x : s) t.push_back(x);
  cout << t;
  return cout;
}
template <typename T>
ostream &operator<<(ostream &cout, queue<T> q) {
  vector<T> t;
  while (q.size()) {
    t.push_back(q.front());
    q.pop();
  }
  cout << t;
  return cout;
}
template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &cout, map<T1, T2, T3> m) {
  for (auto &x : m) {
    cout << "Key: " << x.first << ' ' << "Value: " << x.second << endl;
  }
  return cout;
}
template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x, const pair<T1, T2> y) {
  x.first += y.first;
  x.second += y.second;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &x, const pair<T1, T2> &y) {
  return make_pair(x.first + y.first, x.second + y.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &x, const pair<T1, T2> &y) {
  return make_pair(x.first - y.first, x.second - y.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> x) {
  return make_pair(-x.first, -x.second);
}
template <typename T>
vector<vector<T>> operator~(vector<vector<T>> vec) {
  vector<vector<T>> v;
  int n = vec.size(), m = vec[0].size();
  v.resize(m);
  for (int i = 0; i < m; i++) {
    v[i].resize(n);
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j] = vec[j][i];
    }
  }
  return v;
}
void print0x(int x) {
  std::vector<int> vec;
  while (x) {
    vec.push_back(x & 1);
    x >>= 1;
  }
  std::reverse(vec.begin(), vec.end());
  for (int i = 0; i < (int)vec.size(); i++) {
    std::cout << vec[i];
  }
  std::cout << ' ';
}
template <typename T>
void print0x(T x, int len) {
  std::vector<int> vec;
  while (x) {
    std::cout << (x & 1);
    x >>= 1;
    len--;
  }
  while (len--) cout << 0;
}
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
using namespace std;
char a[2005];
char b[2005];
int n;
const int Basis = 1001;
struct Value {
  int ways;
  int tot;
  Value() {}
  Value(int a, int b) : ways(a), tot(b) {}
  Value eat(int x) { return Value(ways, (1LL * ways * x + tot) % mod); }
  Value &operator+=(const Value &oth) {
    chadd(ways, oth.ways);
    chadd(tot, oth.tot);
    return (*this);
  }
};
Value _dp[2005][2005];
Value &dp(int x, int y) { return _dp[x + Basis][y]; }
void solve() {
  scanf("%d", &n);
  scanf("%s%s", a, b);
  for (int i = 0; i < n; i++)
    for (int j = -n / 2; j <= n / 2; j++) dp(i, j) = Value(0, 0);
  dp(0, 0) = Value(1, 0);
  for (int i = 0; i < n; i++) {
    for (int j = -i; j <= i; j++) {
      if (j < -n / 2 || j > n / 2) continue;
      for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
          if (a[i] != '?' && a[i] != x + '0') continue;
          if (b[i] != '?' && b[i] != y + '0') continue;
          int sgn = (x - y);
          if (i & 1) sgn *= -1;
          dp(i + 1, j + sgn) += dp(i, j).eat(mabs(j));
        }
      }
    }
  }
  cout << dp(n, 0).tot << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
