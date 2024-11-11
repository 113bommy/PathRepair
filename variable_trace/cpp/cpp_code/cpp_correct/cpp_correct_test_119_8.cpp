#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  multiset<long long> s;
  for (long long &i : v) {
    cin >> i;
    s.insert(i);
  }
  while (s.size() >= 2) {
    auto it = s.begin(), it1 = s.end();
    it1--;
    if (*it1 - *it <= 1) return (*it1 - *it);
    long long x = *it, y = *it1;
    s.erase(it);
    s.erase(it1);
    if ((x + y) & 1) {
      s.insert((x + y) / 2);
      s.insert((x + y) / 2 + 1);
    } else {
      s.insert((x + y) / 2);
      s.insert((x + y) / 2);
    }
  }
  return 0;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) cout << solve() << '\n';
  return 0;
}
