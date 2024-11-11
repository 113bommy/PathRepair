#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    char str[100];
    scanf("%s", str);
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < strlen(str); i++) {
      if (str[i] == 'A') {
        a++;
      } else if (str[i] == 'B') {
        b++;
      } else {
        c++;
      }
    }
    int d = a + c;
    if (d == b) {
      printf("YES\n");
    } else
      printf("NO\n");
  }
  return 0;
}
