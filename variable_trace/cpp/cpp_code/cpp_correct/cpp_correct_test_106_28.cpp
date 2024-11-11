#include <bits/stdc++.h>
int main() {
  int t, n, i, j;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d", &n);
    for (j = 2; j <= n + 1; j++) printf("%d ", j);
    printf("\n");
  }
  return 0;
}
