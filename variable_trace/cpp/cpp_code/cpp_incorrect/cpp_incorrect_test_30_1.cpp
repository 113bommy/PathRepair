#include <bits/stdc++.h>
using namespace std;
long long ispalindrome(string &s, char a, long long n) {
  long long i = 0;
  long long j = n - 1;
  long long count = 0;
  while (i < j) {
    if (s[i] == s[j]) {
      i++;
      j--;
    } else {
      if (s[i] == a) {
        i++;
        count++;
      } else if (s[j] == a) {
        j--;
        count++;
      } else {
        return n + 1;
      }
    }
  }
  return count;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long result = INT_MAX;
  for (long long i = 0; i < 25; i++) {
    long long count = ispalindrome(s, 'a' + i, n);
    result = min(result, count);
  }
  if (result == n + 1) {
    cout << -1 << "\n";
    return;
  }
  cout << result << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
