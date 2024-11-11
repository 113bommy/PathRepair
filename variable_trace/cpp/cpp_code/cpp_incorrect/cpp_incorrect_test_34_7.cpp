#include <bits/stdc++.h>
int *ei[5000 + 1], eo[5000 + 1];
void append(int a, int i) {
  int o = eo[a]++;
  if (o >= 2 && (o & o - 1) == 0)
    ei[a] = (int *)realloc(ei[a], o * 2 * sizeof *ei[a]);
  ei[a][o] = i;
}
int main() {
  static int ii[8192], bb[8192], bb_[8192];
  static char in[8192];
  int n, h, h_, i, a, b, o, cnt;
  scanf("%d", &n);
  for (a = 0; a <= 5000; a++) ei[a] = (int *)malloc(2 * sizeof *ei[a]);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    append(a, i);
  }
  for (b = 0; b < 8192; b++) ii[b] = n, bb[b] = b;
  ii[0] = -1;
  for (a = 1; a <= 5000; a++) {
    memset(in, 0, 8192 * sizeof *in);
    cnt = 0;
    for (o = 0, h = 0; o <= eo[a]; o++, h = h_) {
      i = o == eo[a] ? n + 1 : ei[a][o];
      h_ = h;
      while (h_ < 8192 && ii[bb[h_]] < i) {
        if (!in[b = bb[h_]]) in[b] = 1, bb_[cnt++] = b;
        h_++;
      }
      h_ = h;
      while (h_ < 8192 && ii[bb[h_]] < i) {
        if (in[bb[h_]] == 1 && !in[b = bb[h_] ^ a])
          in[b] = 2, ii[b] = i, bb_[cnt++] = b;
        h_++;
      }
    }
    memcpy(bb, bb_, 8192 * sizeof *in);
  }
  cnt = 0;
  for (b = 0; b < 8192; b++)
    if (ii[b] != n) cnt++;
  printf("%d\n", cnt);
  for (b = 0; b < 8192; b++)
    if (ii[b] != n) printf("%d ", b);
  printf("\n");
  return 0;
}
