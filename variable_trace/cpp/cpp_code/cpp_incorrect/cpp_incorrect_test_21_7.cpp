#include <bits/stdc++.h>
using namespace std;
const int NMAX = 102;
const int LINMAX = NMAX * NMAX * NMAX;
int N, M, K, P;
int memo[LINMAX + 5];
int fact[NMAX + 2], c[NMAX + 2][NMAX + 2];
int comb(int k, int n) { return c[n][k]; }
int index(int a, int b, int c) { return a * 101 * 101 + b * 101 + c; }
int ways(int len, int levels_deep, int count) {
  int ind = index(len, levels_deep, count);
  if (memo[ind] != -1) {
    return memo[ind];
  }
  if (count > len || (len > 1 && count > len / 2)) {
    return memo[ind] = 0;
  }
  if (len == 0) {
    if (count == 0) {
      return memo[ind] = 1;
    } else {
      return memo[ind] = 0;
    }
  }
  if (levels_deep == 1) {
    if (count <= 0 || count >= 2) {
      return memo[ind] = 0;
    }
    return memo[ind] = fact[len];
  }
  int res = 0;
  res = (res + ways(len - 1, levels_deep - 1, count)) % P;
  for (int pos_me = 2; pos_me < len; pos_me++) {
    for (int c1 = 0; c1 <= count; c1++) {
      res = (res + 1LL * comb(pos_me - 1, len - 1) *
                       ways(pos_me - 1, levels_deep - 1, c1) % P *
                       ways(len - pos_me, levels_deep - 1, count - c1)) %
            P;
    }
  }
  if (len != 1) {
    res = (res + ways(len - 1, levels_deep - 1, count)) % P;
  }
  return memo[ind] = res;
}
int main() {
  cin >> N >> M >> K >> P;
  fact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = (1LL * i * fact[i - 1]) % P;
  }
  c[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % P;
    }
  }
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      for (int k = 0; k <= N; k++) {
        memo[index(i, j, k)] = -1;
      }
    }
  }
  cout << ways(N, M, K) << '\n';
  return 0;
}
