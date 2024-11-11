#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) {
  cout << a << " ";
  debug(args...);
}
const int N = 2e5 + 15;
const long long mod = 1e9 + 7;
const double E = 1e-7;
long long A[N];
int dg(long long a) {
  int ans = 0;
  while (a) {
    a /= 10;
    ans++;
  }
  return ans;
}
long long n, h;
bool f(long long mid) {
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    long long dis = abs(A[i] - A[i - 1]);
    long long end = A[i - 1] + mid;
    dis = min(dis, end - A[i - 1]);
    ans += dis;
  }
  ans += mid;
  return ans >= h;
}
void solve() {
  cin >> n >> h;
  for (int i = 0; i < n; i++) cin >> A[i];
  long long a = -1, b = 2e18, mid;
  while (b - a > 1) {
    mid = (a + b) >> 1;
    if (f(mid))
      b = mid;
    else
      a = mid;
  }
  cout << b << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
