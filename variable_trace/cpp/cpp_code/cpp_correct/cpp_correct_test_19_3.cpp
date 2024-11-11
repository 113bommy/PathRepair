#include <bits/stdc++.h>
using namespace std;
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void init_code() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int n;
vector<int> a;
int dp[10001][2011];
int make(int i, int val = 0) {
  if (val >= 2010) return 1e9;
  if (val < 0) return 1e9;
  if (i == n) {
    return val;
  }
  if (dp[i][val] == -1) {
    if (i == 0) {
      dp[i][val] = max(val, min({make(i + 1, val + a[i]),
                                 make(i + 1, val - a[i]), make(i, val + 1)}));
    } else
      dp[i][val] =
          max(val, min(make(i + 1, val + a[i]), make(i + 1, val - a[i])));
  }
  return dp[i][val];
}
void solve() {
  cin >> n;
  a.clear();
  for (int i = 0; i < n; i++) {
    int el;
    cin >> el;
    a.push_back(el);
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 2010; j++) {
      dp[i][j] = -1;
    }
  }
  cout << make(0, 0) << "\n";
}
signed main() {
  init_code();
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
