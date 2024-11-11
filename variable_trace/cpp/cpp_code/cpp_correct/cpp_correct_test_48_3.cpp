#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug &operator<<(const c &) {
    return *this;
  }
};
template <typename T>
void read(T &x) {
  cin >> x;
}
template <typename T, typename U>
void read(T &x, U &y) {
  cin >> x >> y;
}
template <typename T>
void read(vector<T> &a) {
  for (T &x : a) read(x);
}
template <typename T>
T cd(T u, T v) {
  return (u + v - 1) / v;
}
void solve() {
  long long n;
  read(n);
  vector<long long> a(n);
  read(a);
  auto v = a;
  sort(v.begin(), v.end());
  if (n <= 2) {
    cout << (a == v ? "YES\n" : "NO\n");
    return;
  }
  map<long long, set<long long>> mp;
  for (long long i = 0; i < n; i++) mp[a[i]].insert(i);
  for (long long i = 0; i < n - 2; i++) {
    if (a[i] == v[i]) {
      mp[a[i]].erase(i);
    } else {
      long long j = *mp[v[i]].begin();
      long long k = (j == n - 1) ? n - 2 : n - 1;
      mp[a[i]].erase(i);
      mp[a[k]].erase(k);
      mp[a[j]].erase(j);
      long long temp = a[i];
      a[i] = a[j];
      a[j] = a[k];
      a[k] = temp;
      mp[a[k]].insert(k);
      mp[a[j]].insert(j);
      assert(set<long long>({i, j, k}).size() == 3);
    }
    debug() << " ["
            << "mp"
               ": "
            << (mp) << "] ";
  }
  long long mx = 0;
  for (long long i = 0; i < n - 2; i++) mx = max(mx, a[i]);
  if (mx > min(a[n - 1], a[n - 2])) {
    cout << "NO\n";
    return;
  }
  for (long long i = n - 2; i < n; i++) {
    if (a[i] != v[i]) {
      map<long long, long long> mpp;
      for (long long j = 0; j < n; j++) mpp[a[j]]++;
      for (auto &p : mpp) {
        if (p.second >= 2) {
          cout << "YES\n";
          return;
        }
      }
      cout << "NO\n";
      return;
    }
  }
  assert(is_sorted(a.begin(), a.end()));
  cout << "YES\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  read(t);
  for (long long testcase = 1; testcase <= t; testcase++) {
    solve();
  }
  return 0;
}
