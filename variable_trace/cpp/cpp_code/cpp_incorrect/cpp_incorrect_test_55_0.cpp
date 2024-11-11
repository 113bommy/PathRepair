#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
void _print(long long int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
void null_pointer() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
}
bool isprime(long long int a) {
  if (a == 1) return false;
  if (a == 2) return true;
  if (a % 2 == 0) return false;
  for (long long int i = 3; (i * i) <= a; i += 2) {
    if (a % i == 0) return false;
  }
  return true;
}
long long int bpow(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % mod;
    }
    b >>= 1;
    a = (a * a) % mod;
  }
  return res % mod;
}
long long int add(long long int a, long long int b) {
  return ((a % mod + b % mod) % mod);
}
long long int sub(long long int a, long long int b) {
  return ((a % mod - b % mod + mod) % mod);
}
long long int mul(long long int a, long long int b) {
  return (((a % mod) * (b % mod)) % mod);
}
long long int divi(long long int a, long long int b) {
  return (mul(a, bpow(b, mod - 2)) % mod);
}
vector<long long int> fact(2000, 0ll);
void factorial() {
  fact[0] = 1, fact[1] = 1;
  for (long long int i = 2; i < 2000; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
}
long long int ncr(long long int n, long long int r) {
  if (r > n) return 0;
  long long int ans = fact[n] % mod;
  ans *= bpow(fact[r], mod - 2) % mod;
  ans %= mod;
  ans *= bpow(fact[n - r], mod - 2) % mod;
  ans %= mod;
  return ans;
}
signed main() {
  null_pointer();
  long long int tt = 1;
  while (tt--) {
    long long int n;
    cin >> n;
    if (n == 1) {
      cout << 6 << "\n";
      continue;
    }
    long long int no4 = bpow(2, n) - 2;
    long long int ans = bpow(4, no4);
    ans = mul(ans, 6);
    cout << ans << "\n";
  }
  return 0;
}
