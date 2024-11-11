#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n;
int a[N];
void solve() {
  scanf("%d", &n);
  int now = 1;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (n == 1) {
    if (a[1] == 1)
      printf("2\n");
    else
      printf("1\n");
    return;
  }
  if (a[1] == 1) now++;
  for (int i = 2; i <= n; i++) {
    if (a[i] == 0 && a[i - 1] == 0) {
      now = -1;
      printf("%d\n", now);
      return;
    }
    if (a[i] == 0) continue;
    if (a[i] == 1 && a[i - 1] == 1)
      now += 5;
    else
      now++;
  }
  printf("%d\n", now);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
