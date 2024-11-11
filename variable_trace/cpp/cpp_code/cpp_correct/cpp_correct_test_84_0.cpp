#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long cal[100005];
long long val[100005];
vector<int> prime;
long long dp[25][100005];
long long cal2(int l, int r) {
  if (l > r) return 0;
  long long tot = 0;
  long long last = r;
  for (int i = 1;;) {
    int Next = (r) / (i + 1);
    if (Next < l) {
      tot += cal[i] * (last - l + 1);
      break;
    }
    tot += cal[i] * (last - Next);
    last = Next;
    i = r / Next;
  }
  return tot;
}
void dc(int k, int l, int r, int optl, int optr) {
  if (l > r) return;
  int mid = (l + r) / 2;
  int opt = 0;
  dp[k][mid] = 1e18;
  long long now = cal2(optr + 1, mid);
  for (int i = min(optr, mid); i >= optl; i--) {
    now += cal[mid / i];
    long long val = dp[k - 1][i - 1] + now;
    if (val < dp[k][mid]) {
      dp[k][mid] = val;
      opt = i;
    }
  }
  dc(k, l, mid - 1, optl, opt);
  dc(k, mid + 1, r, opt, optr);
}
void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (k >= 20)
    printf("%d\n", n);
  else {
    printf("%lld\n", dp[k][n]);
  }
}
int main() {
  for (int i = 1; i <= 100000; i++) val[i] = i;
  for (int i = 2; i <= 100000; i++) {
    if (val[i] == i) {
      for (int j = i; j <= 100000; j += i) val[j] = val[j] / i * (i - 1);
    }
  }
  cal[1] = 1;
  for (int i = 2; i <= 100000; i++) cal[i] = cal[i - 1] + val[i];
  for (int i = 1; i <= 100000; i++) {
    dp[1][i] = i * 1ll * (i + 1) / 2;
  }
  for (int i = 2; i <= 20; i++) {
    dc(i, 1, 100000, 1, 100000);
  }
  int t = 1;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
