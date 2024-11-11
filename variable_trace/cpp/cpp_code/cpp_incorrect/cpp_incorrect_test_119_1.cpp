#include <bits/stdc++.h>
using namespace std;
template <class A>
void read(vector<A>& v);
template <class A, size_t second>
void read(array<A, second>& a);
template <class T>
void read(T& x) {
  cin >> x;
}
void read(double& d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double& d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T>
void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template <class A>
void read(vector<A>& x) {
  for (auto& a : x) read(a);
}
template <class A, size_t second>
void read(array<A, second>& x) {
  for (auto& a : x) read(a);
}
void solve() {
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ans += x;
  }
  if (ans % n == 0) {
    cout << 0 << endl;
  } else {
    cout << ans % n << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
