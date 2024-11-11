#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<long long>;
using vpii = vector<pair<int, int>>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvpii = vector<vector<pair<int, int>>>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  long double d;
  cin >> d;
  long long p = d * 10000;
  long long l = 0, r = n;
  while (l < r) {
    long long x = (l + r) >> 1;
    if (5000LL * (2 * x * (x - 1) * (x - 2) + 6 * x * (x - 1) * (n - x) +
                  3 * x * (n - x) * (n - x - 1)) >=
        p * n * (n - 1) * (n - 2))
      r = x;
    else
      l = x + 1;
  }
  cout << l << "\n";
}
