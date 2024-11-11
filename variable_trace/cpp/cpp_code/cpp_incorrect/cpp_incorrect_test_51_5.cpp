#include <bits/stdc++.h>
const unsigned int M = 1000000007;
const int INF = 0x3f3f3f3f;
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
vector<long long> sieve(int n) {
  int *arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long expo(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
long long powerLL(long long x, long long n) {
  long long result = 1;
  while (n) {
    if (n & 1) result = result * x % M;
    n = n / 2;
    x = x * x % M;
  }
  return result;
}
void print(int row, int col, vector<vector<int>> dp) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
vector<long long> primeFactors(long long n) {
  vector<long long> v;
  while (n % 2 == 0) {
    v.push_back(2);
    n = n / 2;
  }
  for (long long i = 3; i * i <= n; i = i + 2) {
    while (n % i == 0) {
      v.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) {
    v.push_back(n);
  }
  return v;
}
vector<long long> factors(long long n) {
  vector<long long> v;
  for (long long i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i) {
        v.push_back(i);
      } else {
        v.push_back(i);
        v.push_back(n / i);
      }
    }
  }
  return v;
}
struct DSU {
  vector<int> parent;
  vector<int> rank;
  int numComp;
  int t;
  DSU(int n) {
    numComp = n;
    t = n;
    parent.resize(n + 1);
    rank.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      parent[i] = i;
    }
  }
  int findParent(int u) {
    if (parent[u] == u) return u;
    return parent[u] = findParent(parent[u]);
  }
  void merge(int u, int v) {
    u = findParent(u);
    v = findParent(v);
    if (u == v)
      return;
    else if (rank[u] > rank[v]) {
      parent[v] = u;
    } else if (rank[v] > rank[u]) {
      parent[u] = v;
    } else
      parent[u] = v, rank[v]++;
    numComp--;
  }
};
bool intersect(pair<long long, long long> c, pair<long long, long long> d) {
  if (c.first > d.first) swap(c, d);
  return c.second > d.first and c.second < d.second;
}
void solve() {
  long long n, p, i, j, o, x, m, k, time, f = 0, e = 0;
  cin >> n;
  if (n == 1) {
    cout << 0 << " " << 1 << "\n";
    return;
  }
  long long a = n++;
  cout << -a << " " << n << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
}
