#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using ull = unsigned long long;
template <typename T>
void print(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << '\n';
}
template <typename T>
void print(vector<vector<T>>& v) {
  for (vector<T>& vv : v) {
    for (T& i : vv) cout << i << " ";
    cout << '\n';
  }
}
template <typename T>
void print(T&& t) {
  cout << t << '\n';
}
template <typename T, typename... Args>
void print(T&& t, Args&&... args) {
  cout << t << " ";
  print(forward<Args>(args)...);
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void loop() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  cin >> a;
  if (n == 1) {
    print("Alice");
    return;
  }
  vector<ll> inc, dec;
  inc.push_back(a[0]);
  for (ll i = 0; i < n - 1; i++) {
    if (a[i] < a[i + 1]) {
      inc.push_back(a[i + 1]);
    } else
      break;
  }
  dec.push_back(a[n - 1]);
  for (ll i = n - 1; i > 0; i--) {
    if (a[i] < a[i - 1]) {
      dec.push_back(a[i - 1]);
    } else
      break;
  }
  if (dec.size() % 2) {
    print("Alice");
    return;
  } else if ((inc.size() - 1 + dec.size()) % 2 == 0) {
    print("Alice");
    return;
  }
  print("Bob");
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  t = 1;
  while (t--) {
    loop();
  }
}
