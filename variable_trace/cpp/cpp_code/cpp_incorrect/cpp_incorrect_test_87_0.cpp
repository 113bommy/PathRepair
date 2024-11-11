#include <bits/stdc++.h>
using namespace std;
void Rohith() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void merge(int a[], int lo, int mid, int hi) {
  int i = lo, j = mid + 1, temp[hi - lo + 1], idx = 0;
  while (i <= mid && j <= hi) {
    if (a[i] <= a[j])
      temp[idx++] = a[i++];
    else
      temp[idx++] = a[j++];
  }
  while (i <= mid) temp[idx++] = a[i++];
  while (j <= hi) temp[idx++] = a[j++];
  for (int i = lo; i <= hi; i++) a[i] = temp[i - lo];
}
void MS(int a[], int lo, int hi) {
  if (lo == hi) return;
  int mid = (lo + hi) / 2;
  MS(a, lo, mid);
  MS(a, mid + 1, hi);
  merge(a, lo, mid, hi);
}
template <typename T>
inline T gcd(T x, T y) {
  return y ? gcd(y, x % y) : x;
}
template <typename T>
inline T LCM(T x, T y) {
  return x / gcd(x, y) * y;
}
int prec(char c) {
  if (c == '^')
    return 3;
  else if (c == '/')
    return 2;
  else if (c == '*')
    return 1;
  else if (c == '+' || c == '-')
    return -1;
  else
    return -2;
}
void solve() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > i) {
      ans += abs(a[i] - (i + ans));
    }
  }
  cout << ans << "\n";
}
int main() {
  Rohith();
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
