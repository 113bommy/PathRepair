#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
bool sorta(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
bool sortd(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second > b.second);
}
void printarr(long long arr[], long long n) {
  for (int i = 0; i < n; i++) cout << arr[i] << ' ';
  cout << ' ';
}
void printvec(vector<long long> arr, long long n) {
  for (int i = 0; i < n; i++) cout << arr[i] << ' ';
  cout << ' ';
}
long long binaryToDecimal(string n) {
  string num = n;
  long long dec_value = 0;
  int base = 1;
  int len = num.length();
  for (int i = len - 1; i >= 0; i--) {
    if (num[i] == '1') dec_value += base;
    base = base * 2;
  }
  return dec_value;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool isPowerOfTwo(int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(long long x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
long long moduloMultiplication(long long a, long long b, long long mod) {
  long long res = 0;
  a %= mod;
  while (b) {
    if (b & 1) res = (res + a) % mod;
    b >>= 1;
  }
  return res;
}
long long powermod(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    long long res = 0;
    for (long long &e : v) {
      cin >> e;
    }
    sort(v.begin(), v.end());
    long long start = n - (2 * k);
    long long count = 1;
    long long i = n - 1;
    while (count <= k) {
      res += v[i - 2] / v[i];
      count++;
      i--;
    }
    for (long long i = 0; i < start; i++) {
      res += v[i];
    }
    cout << res << endl;
  }
  return 0;
}
