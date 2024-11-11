#include <bits/stdc++.h>
template <typename T>
auto getint() -> T {
  T ret = 0;
  char c;
  while ((c = getchar()) && !isspace(c)) {
    ret = ret * 10 + c - '0';
  }
  return ret;
}
int main() {
  unsigned T = getint<unsigned>(), cntA, cntB, cntC;
  char c;
  while (T--) {
    cntA = cntB = cntC = 0;
    while ((c = getchar()) && !isspace(c)) {
      if (c == 'A')
        ++cntA;
      else if (c == 'B')
        ++cntB;
      else
        ++cntC;
    }
    printf("%s\n", ((cntA + cntC == cntB) ? "YES" : "NO"));
  }
}
