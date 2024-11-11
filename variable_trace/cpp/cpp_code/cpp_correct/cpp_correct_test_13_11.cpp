#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9 + 7, MAX = 1e6 + 5;
const long long INF = 1e18 + 5;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, int> M;
    for (auto c : s) M[c]++;
    if (M['B'] == M['A'] + M['C'])
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
