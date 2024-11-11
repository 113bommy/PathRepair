#include <bits/stdc++.h>
int main(void) {
  int t, len, i, flag;
  char c[102];
  scanf("%d", &t);
  while (t--) {
    flag = 0;
    scanf("%s", c);
    len = strlen(c);
    if (len % 2 == 0) {
      flag = 1;
      for (i = 0; i < (len / 2) && flag; i++)
        if (c[i] != c[i + len / 2]) flag = 0;
    }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
