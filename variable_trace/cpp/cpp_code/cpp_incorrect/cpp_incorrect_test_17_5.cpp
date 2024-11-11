#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
using ii = pair<long long, long long>;
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % mod;
    y = y / 2, x = (x * x) % mod;
  }
  return res % mod;
}
long long seg[800100];
void build(long long idx, long long l, long long r) {
  long long mid = (l + r) / 2;
  if (l == r) {
    seg[idx] = 0;
    return;
  }
  build(2 * idx, l, mid);
  build(2 * idx + 1, mid + 1, r);
  seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
  return;
}
void upd(long long idx, long long l, long long r, long long ind,
         long long val) {
  if (l == r) {
    seg[idx] = val;
    return;
  }
  long long mid = (l + r) / 2;
  if (ind <= mid and ind >= l) {
    upd(2 * idx, l, mid, ind, val);
  } else {
    upd(2 * idx + 1, mid + 1, r, ind, val);
  }
  seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
  return;
}
long long get(long long idx, long long l, long long r, long long gl,
              long long gr) {
  if (l >= gl and r <= gr) {
    return seg[idx];
  }
  if (gl > r or gr < l) {
    return 0;
  }
  long long mid = (l + r) / 2;
  return get(2 * idx, l, mid, gl, gr) + get(2 * idx + 1, mid + 1, r, gl, gr);
}
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  long long b[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(a, a + n);
  map<long long, long long> mpp;
  long long st = 1;
  for (long long i = 0; i < n; i++) {
    if (mpp.find(a[i]) == mpp.end()) {
      mpp[a[i]] = st++;
    }
  }
  long long ans = 0;
  build(1, 0, n);
  for (long long i = 0; i < n; i++) {
    long long sim = get(1, 0, n, mpp[b[i]], mpp[b[i]]);
    upd(1, 0, n, mpp[b[i]], 1);
    long long sm = get(1, 0, n, 0, mpp[b[i]] - 1);
    ans += min(i - sm - sim, sm);
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
