#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long double Pi = 3.141592653;
const long long mod = 1e9 + 7;
long long INF = 1000000000000000000;
struct mycmp {
  bool operator()(pair<int, int> a, pair<int, int> b) const {
    return (a.first < b.first) || (a.first == b.first && a.second > b.second);
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    long long x = 0, y = 0;
    long long xmin = 0, xmax = 0, ymin = 0, ymax = 0;
    long long x1 = 0, y1 = 0;
    for (int i = 0; i < s.length(); i++) {
      int cnt = 0;
      if (s[i] == 'U')
        --x, ++cnt;
      else if (s[i] == 'D')
        ++x, ++cnt;
      else if (s[i] == 'R')
        ++y, --cnt;
      else
        --y, --cnt;
      xmin = min(xmin, x);
      xmax = max(xmax, x);
      ymin = min(ymin, y);
      ymax = max(ymax, y);
      long long totalx = abs(xmin) + xmax + 1;
      long long totaly = abs(ymin) + ymax + 1;
      if (totalx <= n && totaly <= m) {
        x1 = abs(xmin);
        y1 = abs(ymin);
      }
    }
    cout << x1 + 1 << " " << y1 + 1 << "\n";
  }
}
