#include <bits/stdc++.h>
using namespace std;
long long pow_mod(long long nn, long long pp, long long mm) {
  long long res = 1;
  while (pp > 0) {
    if (pp & 1) res = (res * nn) % mm;
    pp = pp >> 1;
    nn = (nn * nn) % mm;
  }
  return res;
}
long long _gcd(long long a, long long b) {
  if (b == 0) return a;
  return _gcd(b, a % b);
}
void dhimanda();
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int i = int(1); i <= int(t); i++) {
    dhimanda();
  }
  return 0;
}
void dhimanda() {
  string a, b;
  cin >> a >> b;
  std::map<char, int> map;
  map.clear();
  for (int i = 0; i < a.size(); ++i) {
    map[a[i]]++;
  }
  int ans = 0;
  for (int i = 0; i < b.size() - 1; ++i) {
    ans += abs(map[b[i]] - map[b[i + 1]]);
  }
  cout << ans << '\n';
}
