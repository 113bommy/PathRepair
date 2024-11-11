#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int cnt[40];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      for (int i = 1; i <= 30; i++)
        if (x >> i & 1) cnt[i]++;
    }
    int g = 0;
    for (int i = 1; i <= 30; i++) g = gcd(g, cnt[i]);
    for (int i = 1; i <= n; i++)
      if (g % i == 0) cout << i << ' ';
    cout << endl;
  }
  return 0;
}
