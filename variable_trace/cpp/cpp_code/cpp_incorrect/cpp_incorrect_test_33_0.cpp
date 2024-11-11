#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int f[511];
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(f, 0x3f, sizeof f);
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 510; j++) {
      if (a[i] > f[j]) {
        f[j ^ a[i]] = min(f[j ^ a[i]], a[i]);
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i <= 500; i++) {
    if (f[i] != 0x3f3f3f3f) cnt++;
  }
  cout << cnt << endl;
  for (int i = 0; i <= 500; i++) {
    if (f[i] != 0x3f3f3f3f) cout << i << " ";
  }
  return 0;
}
