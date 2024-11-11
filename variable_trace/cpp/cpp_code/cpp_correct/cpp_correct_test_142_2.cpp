#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  long long int p = sqrt(n);
  for (int i = 5; i <= p; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
string d2b(int n) {
  string s;
  for (int i = 31; i >= 0; i--) {
    int k = n >> i;
    if (k & 1)
      s += '1';
    else
      s += "0";
  }
  return s;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int b2d(string n) {
  string num = n;
  long long int dec_value = 0;
  long long int base = 1;
  long long int len = num.length();
  for (int i = len - 1; i >= 0; i--) {
    if (num[i] == '1') dec_value += base;
    base = base * 2;
  }
  return dec_value;
}
bool check(long long int x, vector<vector<long long int>> &v) {
  long long int m = v.size();
  long long int n = v[0].size();
  unordered_map<long long int, long long int> mp;
  for (long long j = 0; j < n; j++) {
    bool f = 0;
    for (long long i = 0; i < m; i++) {
      if (v[i][j] >= x) {
        f = 1;
        break;
      }
    }
    if (f == 0) return 0;
  }
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < n; j++) {
      if (v[i][j] >= x) {
        if (mp[i] == 1) {
          return 1;
        }
        mp[i] = 1;
      }
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test_case = 1;
  cin >> test_case;
  while (test_case--) {
    long long int n, m;
    cin >> m >> n;
    vector<vector<long long int>> a(m, vector<long long int>(n));
    long long int l = INT_MAX, h = INT_MIN;
    for (long long i = 0; i < m; i++) {
      for (long long j = 0; j < n; j++) {
        cin >> a[i][j];
        l = min(l, a[i][j]);
        h = max(h, a[i][j]);
      }
    }
    long long int mid;
    long long int ans = 0;
    while (l <= h) {
      mid = (l + h) / 2;
      if (check(mid, a)) {
        ans = mid;
        l = mid + 1;
      } else
        h = mid - 1;
    }
    cout << ans << endl;
  }
}
