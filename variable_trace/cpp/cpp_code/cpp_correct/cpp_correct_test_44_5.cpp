#include <bits/stdc++.h>
using namespace std;
const int N = 2100, rev[4] = {0, 2, 1, 3};
int n;
char a[N][N];
int tag[N];
int id[N][N];
void dye(int n) {
  for (int i = 1, c = 1; i <= n; i += 2, c += 2) {
    id[i][1] = id[1][i] = id[1][i + 1] = id[i + 1][1] = c;
    for (int j = 2; j < i; j++) id[j][i + 1 - j] = c + (1 ^ j & 1);
    for (int j = 2; j <= n - i + 1; j++)
      id[i + j][j] = id[j][i + j] = c + (1 ^ j & 1);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n - i + 1; j++) id[n - i + 1][n - j + 1] = id[i][j];
}
int main() {
  scanf("%d", &n);
  if (n & 1) {
    puts("NONE");
    return 0;
  }
  dye(n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", a[i] + 1);
    for (int j = 1; j <= n; j++)
      if (a[i][j] != '.') {
        tag[id[i][j]] |= 1 << (a[i][j] == 'S');
      }
  }
  for (int i = 1; i <= n; i += 2) {
    int &x = tag[i], &y = tag[i + 1];
    y = rev[x |= rev[y]];
  }
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    if (tag[i] == 3) {
      puts("NONE");
      return 0;
    }
    if (!tag[i]) flag = 1;
  }
  if (flag) {
    puts("MULTIPLE");
    return 0;
  }
  puts("UNIQUE");
  for (int i = 1; i <= n; i++, puts(""))
    for (int j = 1; j <= n; j++) putchar(tag[id[i][j]] == 2 ? 'S' : 'G');
}
