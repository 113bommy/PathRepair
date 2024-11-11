#include <bits/stdc++.h>
using namespace std;
template <class a, class b>
ostream& operator<<(ostream& os, const pair<a, b>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  if (!v.size())
    os << "]";
  else
    for (int i = 0; i < v.size(); ++i) os << v[i] << ",]"[i == v.size() - 1];
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& s) {
  os << "{";
  if (!s.size())
    os << "}";
  else
    for (auto x : s) os << x << ",}"[x == *s.rbegin()];
  return os;
}
void printr(ostream& os) { os << '\n'; }
template <class T, class... Args>
void printr(ostream& os, const T& t, const Args&... args) {
  os << t;
  if (sizeof...(args)) os << " ";
  printr(os, args...);
}
template <class T>
void read(T& x) {
  cin >> x;
}
template <class T, class... Args>
void read(T& t, Args&... args) {
  read(t), read(args...);
}
template <class T>
void readarray(T* A, int n) {
  for (__typeof(0) i = (0), _end = (n), _step = 1 - 2 * ((0) > (n)); i != _end;
       i += _step)
    read(A[i]);
}
void dbgr(ostream& os) { os << endl; }
template <class T, class... Args>
void dbgr(ostream& os, const T& t, const Args&... args) {
  os << t;
  if (sizeof...(args)) os << ", ";
  dbgr(os, args...);
}
template <class T>
T min(const vector<T>& v) {
  return *min_element(v.begin(), v.end());
}
template <class T>
T max(const vector<T>& v) {
  return *max_element(v.begin(), v.end());
}
long long pw(long long a, long long k = 998244353 - 2) {
  long long ans = 1;
  for (a %= 998244353; k; k >>= 1) {
    if (k & 1) ans = ans * a % 998244353;
    a = a * a % 998244353;
  }
  return ans;
}
int n, a[500050];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int _;
  read(_);
  while (_--) {
    read(n);
    readarray(a, n);
    sort(a, a + n);
    for (int i = 0; i < n / 2; ++i) cout << a[i] << " " << a[0] << endl;
  }
  return 0;
}
