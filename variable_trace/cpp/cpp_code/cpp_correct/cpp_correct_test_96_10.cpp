#include <bits/stdc++.h>
using namespace std;
const int intmax = 2147483647;
const int intmin = -2147483648;
const int mod = 1000000007;
const int mod2 = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &i : v) in >> i;
  return in;
}
template <typename T>
ostream &operator<<(ostream &ost, vector<T> v) {
  if (&ost == &cerr) {
    cerr << "{";
    int cnt = v.size();
    for (auto x : v) {
      cerr << x;
      cnt--;
      if (cnt) cerr << ", ";
    }
    cerr << "}";
  } else
    for (auto i : v) ost << i << " ";
  return ost;
}
template <typename T>
ostream &operator<<(ostream &ost, set<T> s) {
  if (&ost == &cerr) {
    cerr << "{";
    int cnt = s.size();
    for (auto x : s) {
      cerr << x;
      cnt--;
      if (cnt) cerr << ", ";
    }
    cerr << "}";
  } else
    for (auto i : s) ost << i << " ";
  return ost;
}
template <typename U, typename V>
ostream &operator<<(ostream &ost, map<U, V> &m) {
  if (&ost == &cerr) {
    cerr << "{";
    int cnt = m.size();
    for (auto x : m) {
      cerr << x;
      cnt--;
      if (cnt) cerr << ", ";
    }
    cerr << "}";
  } else
    for (auto i : m) ost << i;
  return ost;
}
template <typename U, typename V>
istream &operator>>(istream &in, pair<U, V> &p) {
  in >> p.first >> p.second;
  return in;
}
template <typename U, typename V>
ostream &operator<<(ostream &ost, pair<U, V> p) {
  if (&ost == &cerr)
    ost << "{" << p.first << ": " << p.second << "}";
  else
    ost << p.first << " " << p.second << " ";
  return ost;
}
template <typename... T>
void read(T &...args) {
  ((cin >> args), ...);
}
template <typename... T>
void print(T... args) {
  ((cout << args << " "), ...);
  cout << '\n';
}
long long binExpp(long long a, long long b, long long modulo) {
  long long prod = a;
  long long ans = 1;
  while (b) {
    if (b % 2) ans = (ans * prod) % modulo;
    b /= 2;
    prod = (prod * prod) % modulo;
  }
  return ans;
}
template <const int mod>
class Mint {
  long long val;

 public:
  Mint(long long _val) { val = (_val % mod + mod) % mod; }
  Mint() { val = 0; }
  Mint operator+(Mint b) { return Mint((this->val + b.val) % mod); }
  Mint operator-(Mint b) { return Mint(this->val - b.val + mod) % mod; }
  Mint operator*(Mint b) { return Mint((this->val * b.val) % mod); }
  Mint operator/(Mint b) {
    return (Mint(binExpp(b(), mod - 2, mod)) * (*this));
  }
  long long &operator()() { return val; }
  Mint operator+=(Mint b) { return *this = *this + b; }
  Mint operator-=(Mint b) { return *this = *this - b; }
  Mint operator*=(Mint b) { return *this = *this * b; }
  Mint operator/=(Mint b) { return *this = *this / b; }
  int operator%(int modulo) { return val % modulo; }
  int operator%(Mint modulo) { return val % (modulo()); }
  Mint operator++() { return *this = *this + Mint(1); }
  Mint operator=(int x) { return (*this).val = (x % mod + mod) % mod; }
  Mint operator^(Mint pow) { return Mint(binExpp((*this)(), pow(), mod)); }
};
template <const int mod>
istream &operator>>(istream &in, Mint<mod> &a) {
  return in >> a();
}
template <const int mod>
ostream &operator<<(ostream &outt, Mint<mod> a) {
  return outt << a();
}
template <const int mod>
Mint<mod> operator+(int mul, Mint<mod> m) {
  return m + mul;
}
template <const int mod>
Mint<mod> operator*(int mul, Mint<mod> m) {
  return m * Mint<mod>(mul);
}
template <const int mod>
vector<Mint<mod>> Factorial(int n) {
  vector<Mint<mod>> fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = i * fact[i - 1];
  return fact;
}
using mint = Mint<1000000007>;
using mint2 = Mint<998244353>;
using vmi = vector<mint>;
auto fact = Factorial<mod2>(100000);
inline mint2 C(mint2 n, mint2 r) {
  return fact[n()] / (fact[r()] * fact[(n - r)()]);
}
mint2 rec(mint2 n, mint2 x, vector<vector<int>> &dp) {
  if (dp[n()][x()] != -1) return dp[n()][x()];
  mint2 res = 0;
  res += x() / (n() - 1) * ((n - 1) ^ n);
  if (x() % (n() - 1)) res += mint2(x() % (n() - 1)) ^ n;
  if (x() > n() - 1) {
    for (int j = 2; j < n(); j++) {
      mint2 ways = 1;
      mint2 f = 0;
      for (int k = 1; k < x() / (n() - 1) + 1; k++) {
        f = ((n - 1) ^ (n - j));
        ways = C(n, j) * (f);
        res += ways * rec(j, x() - k * (n() - 1), dp);
      }
    }
  }
  return dp[n()][x()] = res();
}
void solve() {
  int n, x;
  cin >> n >> x;
  vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
  cout << rec(n, x, dp) << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  for (int var = 1; var < t + 1; var++) solve();
  return 0;
}
