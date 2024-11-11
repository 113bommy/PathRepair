#include <bits/stdc++.h>
using namespace std;
char a[26];
int num[26];
int main() {
  int n;
  scanf("%d", &n);
  char b[50];
  for (int i = 0; i < n; i++) {
    int time = 0;
    scanf("%s", &a);
    scanf("%s", &b);
    for (int i1 = 0; i1 < 26; i1++) {
      num[a[i1] - 'a'] = i1;
    }
    for (int i2 = 0; i2 < strlen(b) - 1; i2++) {
      time += abs(num[b[i2 + 1] - 'a'] - num[b[i2] - 'a']);
    }
    printf("������Ϊ%d\n", time);
  }
}
