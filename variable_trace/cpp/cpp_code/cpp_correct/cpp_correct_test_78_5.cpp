#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
void slv() {
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bool pokita = 0;
  for (int i = 0; i < n; i++) {
    pokita = pokita or a[i];
  }
  if (!pokita) {
    for (int i = 0; i < n; i++) {
      printf("%d ", i + 1);
    }
    printf("\n");
    return;
  }
  vi cnt(30);
  for (int j = 0; j < 30; j++) {
    for (int i = 0; i < n; i++) {
      if (a[i] & (1 << j)) cnt[j]++;
    }
  }
  int g = 0;
  for (int j = 0; j < 30; j++) {
    g = gcd(g, cnt[j]);
  }
  vi pans;
  for (int i = 1; i <= sqrt(g); i++) {
    if (g % i == 0) {
      pans.push_back(i);
      if (i != g / i) pans.push_back(g / i);
    }
  }
  sort(pans.begin(), pans.end());
  for (auto x : pans) {
    printf("%d ", x);
  }
  printf("\n");
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int cs = 0; cs < t; cs++) slv();
  return 0;
}
