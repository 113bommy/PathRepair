#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int inf = 1e9;
const long long mod = 1e9 + 7;
const int N = 1e6 + 8;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    set<int> st;
    for (int i = 1; i <= n; i++) st.insert(i);
    vector<int> rem;
    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      if (st.find(x) != st.end())
        st.erase(x);
      else
        rem.push_back(x);
    }
    sort(rem.begin(), rem.end());
    reverse(rem.begin(), rem.end());
    int pt = 0;
    bool err = false;
    for (auto &z : rem) {
      auto it = st.end();
      it--;
      int ctg = (*it);
      if (ctg > (z - 1) / 2) {
        err = true;
        break;
      }
      st.erase(it);
    }
    if (err)
      cout << "-1\n";
    else {
      cout << rem.size();
    }
  }
  return 0;
}
