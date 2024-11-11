#include <bits/stdc++.h>
using namespace std;
void yes() {
  cout << "YES"
       << "\n";
  return;
}
void no() {
  cout << "NO"
       << "\n";
  return;
}
template <typename T>
void p(T a) {
  cout << a << " ";
  return;
}
template <typename T>
void pnl(T a) {
  cout << a << "\n";
  return;
}
const int ten4 = 1e4;
const int ten5 = 1e5;
const int ten6 = 1e6;
const int ten7 = 1e7;
const int ten9 = 1e9;
const int mod = 1e9 + 7;
struct pair_hash {
  inline std::size_t operator()(const std::pair<int, int>& v) const {
    return v.first * 31 + v.second;
  }
};
long long bin_to_integer(string strin) {
  long long r = 1, sum = 0;
  for (long long i = strin.length() - 1; i >= 0; i--) {
    if (strin[i] == '1') sum += r;
    r *= 2;
  }
  return sum;
}
string to_binary(int n) {
  string strng;
  while (n > 0) {
    if (n & 1)
      strng += '1';
    else
      strng += '0';
    n >>= 1;
  }
  reverse(strng.begin(), strng.end());
  return strng;
}
int compare(const void* a, const void* b) {
  const long long* x = (long long*)a;
  const long long* y = (long long*)b;
  if (*x > *y)
    return 1;
  else if (*x < *y)
    return -1;
  return 0;
}
int power(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = (res * 1LL * a) % mod;
    n /= 2;
    a = (a * 1LL * a) % mod;
  }
  return res;
}
const int Nc = 200001;
int F[Nc];
bool Fcomputed = false;
int nCr(int n, int r) {
  if (!Fcomputed) {
    F[0] = 1, Fcomputed = true;
    for (int i = 1; i < Nc; i++) F[i] = (F[i - 1] * 1LL * i) % mod;
  }
  if (n < r) return 0;
  int res = F[n];
  res = res * 1LL * power(F[r], mod - 2) % mod;
  res = res * 1LL * power(F[n - r], mod - 2) % mod;
  return res;
}
struct unionfind {
  vector<int> p;
  unionfind(int N) { p = vector<int>(N, -1); }
  int root(int x) {
    if (p[x] < 0) {
      return x;
    } else {
      p[x] = root(p[x]);
      return p[x];
    }
  }
  bool same(int x, int y) { return root(x) == root(y); }
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (p[x] < p[y]) {
        swap(x, y);
      }
      p[y] += p[x];
      p[x] = y;
    }
  }
};
void testcase(int test) {
  int n;
  cin >> n;
  int arr[n], cnt = 0;
  for (int i = 0; i < (n); i++) cin >> arr[i];
  if (n % 2 == 0) return yes();
  for (int i = 0; i < (n - 1); i++) {
    if (arr[i] >= arr[i + 1]) return yes();
  }
  no();
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  ;
  int test = 1, z = 1;
  cin >> test;
  while (z <= test) {
    testcase(z);
    z++;
  }
  return 0;
}
