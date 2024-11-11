#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    string a, s;
    cin >> a >> s;
    vector<long long int> v;
    long long int x = s.length() - 1, flag = 1;
    for (int i = a.length() - 1; i >= 0; i--) {
      if (x < 0) {
        flag = 0;
        break;
      }
      if (s[x] >= a[i])
        v.push_back(s[x] - a[i]), x--;
      else {
        if (x > 0 && s[x - 1] == '1')
          v.push_back(10 + s[x] - a[i]), x -= 2;
        else {
          flag = 0;
          break;
        }
      }
    }
    if (x >= 0) {
      for (int i = x; i >= 0; i--) {
        v.push_back(s[i] - '0');
      }
    }
    if (flag == 0)
      cout << "-1\n";
    else {
      long long int p = 0;
      reverse(v.begin(), v.end());
      for (auto i : v) {
        if (i != 0) p = 1;
        if (p == 1) cout << i;
      }
      cout << endl;
    }
  }
}
