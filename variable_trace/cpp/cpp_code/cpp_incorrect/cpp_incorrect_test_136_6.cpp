#include <bits/stdc++.h>
using namespace std;
long long int fastpow(long long int a, long long int p) {
  long long int res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % 1000000007;
      p /= 2;
    } else {
      res = res * 1ll * a % 1000000007;
      p--;
    }
  }
  return res;
}
long long int fact(long long int n) {
  long long int res = 1;
  for (long long int i = 1; i <= n; i++) {
    res = res * 1ll * i % 1000000007;
  }
  return res;
}
long long int comb(long long int n, long long int k) {
  return fact(n) * 1ll * fastpow(fact(k), 1000000007 - 2) % 1000000007 * 1ll *
         fastpow(fact(n - k), 1000000007 - 2) % 1000000007;
}
long long int to_integer(string& aa) {
  long long int res = 0;
  for (auto x : aa) res = (res * 10) + (x - '0');
  return res;
}
bool prime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void sieve(long long int n, vector<long long int>& prime) {
  for (long long int p = 2; p * p <= n; p++) {
    if (prime[p] == 1) {
      for (long long int i = p * p; i <= n; i += p) prime[i] = 0;
    }
  }
}
bool check(string s, string a) {
  long long int j = 0;
  for (long long int i = 0; i < s.size(); i++) {
    if (s[i] == a[j]) {
      j++;
    }
    if (j == a.size()) return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> b(n);
    long long int s = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> b[i];
      s += b[i];
    }
    long long int x = n * (n + 1) / 2;
    if (s % x != 0) {
      cout << "NO\n";
      continue;
    }
    long long int f = 0;
    s /= x;
    vector<long long int> ans(n);
    for (long long int i = 0; i < n; i++) {
      if (i != n - 1) {
        long long int tmp = b[i] - b[i + 1] + s;
        if (tmp == 0 || tmp % n != 0) {
          f = 1;
          break;
        }
        ans[i + 1] = tmp / n;
      } else {
        long long int tmp = b[i] - b[0] + s;
        if (tmp == 0 || tmp % n != 0) {
          f = 1;
          break;
        }
        ans[0] = tmp / n;
      }
    }
    if (f) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (auto x : ans) {
        cout << x << " ";
      }
      cout << "\n";
    }
  }
}
