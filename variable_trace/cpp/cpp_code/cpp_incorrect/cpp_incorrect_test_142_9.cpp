#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(char c) {
  string s(1, c);
  return "'" + s + "'";
}
template <class T>
string to_string(vector<T> v) {
  string s = "{";
  bool first = true;
  for (T x : v) {
    if (!first) s += ", ";
    s += to_string(x);
    first = false;
  }
  s += "}";
  return s;
}
template <class T>
string to_string(set<T> v) {
  string s = "{";
  bool first = true;
  for (T x : v) {
    if (!first) s += ", ";
    s += to_string(x);
    first = false;
  }
  s += "}";
  return s;
}
template <class T>
string to_string(unordered_set<T> v) {
  string s = "{";
  bool first = true;
  for (T x : v) {
    if (!first) s += ", ";
    s += to_string(x);
    first = false;
  }
  s += "}";
  return s;
}
template <class T>
string to_string(multiset<T> v) {
  string s = "{";
  bool first = true;
  for (T x : v) {
    if (!first) s += ", ";
    s += to_string(x);
    first = false;
  }
  s += "}";
  return s;
}
template <class T1, class T2>
string to_string(pair<T1, T2> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class T1, class T2>
string to_string(unordered_map<T1, T2> m) {
  string s = "{";
  bool first = true;
  for (auto x : m) {
    if (!first) s += ", ";
    s += "(" + to_string(x.first) + " -> " + to_string(x.second) + ")";
    first = false;
  }
  s += "}";
  return s;
}
template <class T1, class T2>
string to_string(map<T1, T2> m) {
  string s = "{";
  bool first = true;
  for (auto x : m) {
    if (!first) s += ", ";
    s += "(" + to_string(x.first) + " -> " + to_string(x.second) + ")";
    first = false;
  }
  s += "}";
  return s;
}
int m, n;
bool can_joy(vector<vector<int>> p, ll joy) {
  bool flag1 = false;
  for (int i = 0; i < m; i++) {
    int found = 0;
    for (int j = 0; j < n; j++) {
      found += p[i][j] >= joy;
    }
    if (found >= 2) {
      flag1 = true;
      break;
    }
  }
  if (!flag1) return false;
  bool flag2;
  for (int j = 0; j < n; j++) {
    flag2 = false;
    for (int i = 0; i < m; i++) {
      flag2 |= p[i][j] >= joy;
    }
    if (!flag2) return false;
  }
  return true;
}
void solve() {
  cin >> m >> n;
  vector<vector<int>> p(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> p[i][j];
    }
  }
  ll l = 2, r = 1e14, mid;
  while (l < r) {
    ;
    ;
    mid = l + (r - l + 1) / 2;
    bool b = can_joy(p, mid);
    if (b)
      l = mid;
    else
      r = mid - 1;
  }
  assert(l == r);
  cout << l << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
