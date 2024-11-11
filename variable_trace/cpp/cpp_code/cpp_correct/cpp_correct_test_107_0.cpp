#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double PI = acos(-1);
int T;
int n, a, b;
bool check() {
  if (a + b > n - 2) return false;
  if (abs(a - b) > 1) return false;
  int t = ceil(1.0 * (n - 2) / 2);
  if (a > t || b > t) return false;
  return true;
}
void print() {
  if (a > b) {
    int i = 1, j = n;
    int t = a;
    while (t--) printf("%d %d ", i++, j--);
    while (i <= j) printf("%d ", j--);
    puts("");
  } else if (b > a) {
    int i = 1, j = n;
    int t = b;
    while (t--) printf("%d %d ", j--, i++);
    while (i <= j) printf("%d ", i++);
    puts("");
  } else {
    int i = 1, j = n;
    int t = a;
    while (t--) printf("%d %d ", i++, j--);
    while (i <= j) printf("%d ", i++);
    puts("");
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &a, &b);
    if (!check()) {
      puts("-1");
      continue;
    }
    print();
  }
  return 0;
}
