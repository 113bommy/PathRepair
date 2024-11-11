#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int mod = 1e9 + 7;
long long power(int a, long long b) {
  if (b == 0LL) return 1LL;
  long long tmp = power(a, b / 2);
  if (b & 1LL) return (tmp * tmp % mod) * a % mod;
  return tmp * tmp % mod;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  cout << 6 * power(4, (1LL << n) - 2) % mod;
}
