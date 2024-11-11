#include <bits/stdc++.h>
using namespace std;
long long T, n, k, s, ans;
int main() {
  cin >> T;
  while (T--) {
    cin >> s >> n >> k;
    if (k == s) {
      printf("YES\n");
      continue;
    }
    if (k > s) {
      printf("NO\n");
      continue;
    }
    long long num = s + k, cnt = s % k + 1;
    if ((!((s / k) & 1))) cnt = k - cnt;
    num -= cnt;
    if (num <= 2 * n) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
