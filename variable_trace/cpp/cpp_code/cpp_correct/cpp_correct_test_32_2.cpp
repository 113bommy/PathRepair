#include <bits/stdc++.h>
using namespace std;
const long long MD = 1e9 + 7;
const long long Inf = 2e16;
const long long N = 1e5 + 5;
long long arr[N], ps[N], dp[N][2];
long long sqr(long long n) {
  long long l = 0, r = 1e9 + 1;
  while (r - l > 1) {
    long long mid = (r + l) / 2;
    if (mid * mid <= n)
      l = mid;
    else
      r = mid;
  }
  return l;
}
void Main() {
  long long n;
  cin >> n;
  long long sq = 2 * sqr(n) + 5;
  for (long long i = 1; i <= n; i++) cin >> arr[i];
  ps[0] = 0;
  for (long long i = 1; i <= n; i++) ps[i] = arr[i] + ps[i - 1];
  for (long long i = 0; i <= n + 4; i++)
    for (long long j = 0; j <= 1; j++) dp[i][j] = -Inf;
  dp[n][1] = arr[n];
  for (long long i = n - 1; i >= 1; i--) dp[i][1] = max(arr[i], dp[i + 1][1]);
  long long ans = 1;
  for (long long k = 2; k <= sq; k++) {
    if (ans == k - 1) {
      for (long long i = 0; i <= n + 4; i++) dp[i][k % 2] = -Inf;
      for (long long i = n; i >= 1; i--)
        if ((i + k - 1) <= n) {
          if ((ps[i + k - 1] - ps[i - 1]) < dp[i + k][(k - 1) % 2]) {
            dp[i][k % 2] = ps[i + k - 1] - ps[i - 1];
          }
          dp[i][k % 2] = max(dp[i][k % 2], dp[i + 1][k % 2]);
          if (dp[i][k % 2] != -Inf) ans = k;
        }
    }
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
