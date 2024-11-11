#include <bits/stdc++.h>
using namespace std;
long long x, y;
int vx[70];
int vy[70];
int countX, countY;
bool tryy(long long xx, long long yy) {
  if (yy == xx) return true;
  countX = 0;
  countY = 0;
  if (xx == 0) {
    countX = 1;
    vx[0] = 0;
  }
  while (xx != 0) {
    vx[countX] = xx % 2;
    xx = xx / 2;
    countX++;
  }
  if (yy == 0) {
    countY = 1;
    vy[0] = 0;
  }
  while (yy != 0) {
    vy[countY] = yy % 2;
    yy = yy / 2;
    countY++;
  }
  if (countX > countY) return false;
  for (int i = 0; i <= countY - countX; i++) {
    bool ok = true;
    for (int j = 0; j < i; j++)
      if (vy[j] != 1) ok = false;
    if (!ok) continue;
    bool found = true;
    for (int j = 0; j < countX; j++) {
      if (vy[i + j] != vx[j]) found = false;
      if (vx[0] == 0 && vy[0] == 0) found = false;
    }
    if (!found) {
      found = true;
      for (int j = 0; j < countX; j++) {
        if (vy[i + j] != vx[countX - j - 1]) found = false;
        if (vx[0] == 0 && vy[countY - 1] == 0) found = false;
      }
    }
    if (!found) continue;
    for (int j = i + countX; j < countY; j++)
      if (vy[j] != 1) ok = false;
    if (ok) return true;
  }
  return false;
}
void solve() {
  scanf("%lld %lld", &x, &y);
  countX = 0;
  countY = 0;
  if (y == x) {
    printf("YES\n");
    return;
  }
  if (x == 0) {
    while (y != 0) {
      if (y % 2 == 0) {
        printf("NO\n");
        return;
      }
      y = y / 2;
    }
    printf("YES\n");
  }
  if (tryy(x, y)) {
    printf("YES\n");
    return;
  }
  while (x % 2 == 0) x = x / 2;
  if (tryy(x, y)) {
    printf("YES\n");
    return;
  }
  printf("NO\n");
}
int main() { solve(); }
