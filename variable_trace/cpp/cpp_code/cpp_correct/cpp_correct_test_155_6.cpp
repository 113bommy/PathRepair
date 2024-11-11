#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (auto &i : a) cin >> i;
  string s;
  cin >> s;
  vector<long long> x;
  vector<long long> y;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0')
      x.push_back(a[i]);
    else
      y.push_back(a[i]);
  }
  long long cnt = 1;
  map<long long, long long> mp;
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  for (int i = 0; i < x.size(); i++) mp[x[i]] = cnt, cnt++;
  for (int i = 0; i < y.size(); i++) mp[y[i]] = cnt, cnt++;
  for (auto i : a) cout << mp[i] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
