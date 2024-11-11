#include <bits/stdc++.h>
int main() {
  int n, a;
  scanf("%d", &n);
  while (n--) {
    int n1;
    scanf("%d", &n1);
    int bo, ans = 1;
    for (int i = 1; i <= n1; i++) {
      scanf("%d", &a);
      bo = 0;
      for (int j = i + 1; j >= 2; j--) {
        if (a % j != 0) {
          bo = 1;
          break;
        }
      }
      if (bo == 0) ans = 0;
    }
    if (ans == 0)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
