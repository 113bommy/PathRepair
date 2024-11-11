#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
const int INF = 1005000000;
const long long MOD = 998244353LL;
int ni() {
  int x;
  cin >> x;
  return x;
}
long long nl() {
  long long x;
  cin >> x;
  return x;
}
double nd() {
  double x;
  cin >> x;
  return x;
}
string next() {
  string x;
  cin >> x;
  return x;
}
struct Combo {
  vector<long long> facs;
  vector<long long> invfacs;
  int N;
  Combo(int N) {
    this->N = N;
    facs.assign(N + 1, 0);
    invfacs.assign(N + 1, 0);
    facs[0] = 1;
    for (int i = 1; i <= N; i++) {
      facs[i] = (facs[i - 1] * i) % MOD;
    }
    invfacs[N] = power(facs[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) {
      invfacs[i] = (invfacs[i + 1] * (i + 1)) % MOD;
    }
  }
  long long choose(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0LL;
    long long denInv = (invfacs[k] * invfacs[n - k]) % MOD;
    long long ans = (facs[n] * denInv) % MOD;
    return ans;
  }
  long long power(long long x, long long y) {
    long long ans = 1;
    x %= MOD;
    while (y > 0) {
      if (y % 2 == 1) ans = (ans * x) % MOD;
      y /= 2;
      x = (x * x) % MOD;
    }
    return ans;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N = ni();
  int X = ni();
  const int M = 51;
  long long dp[M][M];
  memset(dp, 0, sizeof dp);
  for (int j = 0; j < (X + 1); j++) dp[1][j] = j;
  Combo c(M);
  long long pows[M][M];
  for (int i = 0; i < (M); i++)
    for (int j = 0; j < (M); j++) {
      pows[i][j] = c.power(i, j);
    }
  for (int i = 2; i <= N; i++) {
    for (int j = i; j <= X; j++) {
      for (int k = 1; k <= N; k++) {
        long long val = (c.choose(i, k) * pows[i - 1][N - k]) % MOD;
        dp[i][j] += dp[k][j - (i - 1)] * val;
        dp[i][j] %= MOD;
      }
    }
  }
  long long ans = (pows[X][N] - dp[N][X] + MOD) % MOD;
  cout << ans;
}
