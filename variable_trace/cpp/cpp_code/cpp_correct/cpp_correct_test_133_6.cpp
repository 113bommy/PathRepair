#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, i, j = 0;
    scanf("%d ", &n);
    char s[2 * n + n], q[2 * n + n];
    gets(s);
    for (i = 0; s[i] != '\0'; i++) {
      if (s[i] != ' ') {
        q[j++] = s[i];
      }
    }
    q[j] = '\0';
    int f = 0;
    printf("%c", q[0]);
    for (i = 2; i < strlen(q) - 1; i = i + 2) {
      if (q[i] != q[i - 1]) {
        printf("%c%c", q[i - 1], q[i]);
        f = 1;
      } else {
        printf("%c", q[i]);
      }
    }
    if (f == 1) printf("%c\n", q[strlen(q) - 1]);
    if (f == 0) {
      printf("%ca\n", q[strlen(q) - 1]);
    }
  }
  return 0;
}
