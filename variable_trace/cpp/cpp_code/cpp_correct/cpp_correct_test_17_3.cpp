#include <bits/stdc++.h>
using namespace std;
void readVector(vector<long long> &a) {
  long long n = a.size();
  for (long long i = 0; i < n; i++) cin >> a[i];
}
long long query(vector<long long> &bit, long long idx) {
  long long sum = 0;
  while (idx > 0) {
    sum += bit[idx];
    idx -= idx & -idx;
  }
  return sum;
}
void update(vector<long long> &bit, long long n, long long idx) {
  while (idx <= n) {
    bit[idx]++;
    idx += idx & -idx;
  }
}
long long solve2(vector<long long> &a, vector<long long> &mn, long long idx,
                 map<long long, long long> &eql) {
  if (idx == 0) return 0;
  long long v = min(mn[idx], idx + 1 - eql[a[idx]] - mn[idx]);
  eql[a[idx]]--;
  v += solve2(a, mn, idx - 1, eql);
  return v;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  readVector(a);
  set<long long> s;
  for (auto x : a) s.insert(x);
  map<long long, long long> mp;
  long long idx = 1;
  for (auto x : s) mp[x] = idx++;
  for (long long i = 0; i < n; i++) a[i] = mp[a[i]];
  map<long long, long long> eql;
  for (long long i = 0; i < n; i++) eql[a[i]]++;
  vector<long long> mn(n);
  vector<long long> bit(200001, 0);
  for (long long i = 0; i < n; i++) {
    long long lessthan = query(bit, a[i] - 1);
    mn[i] = lessthan;
    update(bit, 200000, a[i]);
  }
  cout << solve2(a, mn, n - 1, eql) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
