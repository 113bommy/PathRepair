#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 3;
int mod;
int bigmod(int a, int b) {
  int ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = (ans * 1ll * a) % mod;
    }
    a = (a * 1ll * a) % mod;
    b >>= 1;
  }
  return ans;
}
inline int add(int x, int y) { return (x + y >= mod ? x + y - mod : x + y); }
inline int sub(int x, int y) { return (x - y < 0 ? x - y + mod : x - y); }
inline int gun(int x, int y) { return ((x * 1ll * y) % mod); }
inline int vag(int x, int y) { return (x * 1ll * bigmod(y, mod - 2)) % mod; }
int ncr[N][N];
void NCR() {
  ncr[0][0] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j > i)
        ncr[i][j] = 0;
      else if (j == i || j == 0)
        ncr[i][j] = 1;
      else {
        ncr[i][j] = add(ncr[i - 1][j], ncr[i - 1][j - 1]);
      }
    }
  }
}
int dp[N][N][N];
int n, m, k;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k >> mod;
  if (mod == 1 || m + k > n + 1) {
    cout << "0\n";
    return 0;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[0][i][j] = 1;
    }
  }
  NCR();
  for (int len = 1; len <= n; len++) {
    for (int maxi = n - len; maxi >= 0; maxi--) {
      for (int koto = 0; koto <= len; koto++) {
        int ans = 0;
        int tkoto = koto;
        if (maxi + 1 == m) {
          tkoto--;
        }
        if (tkoto < 0) {
          dp[len][maxi][koto] = 0;
          continue;
        }
        for (int i = 0; i < len; i++) {
          int dan = len - i - 1;
          for (int j = min(i, tkoto); j >= 0; j--) {
            if (tkoto - j > dan) break;
            int t3 = gun(ncr[len - 1][i], dp[i][maxi + 1][j]);
            int t2 = dp[dan][maxi + 1][tkoto - j];
            ans = add(ans, gun(t2, t3));
          }
        }
        dp[len][maxi][koto] = ans;
      }
    }
  }
  cout << dp[n][0][k];
  return 0;
}
