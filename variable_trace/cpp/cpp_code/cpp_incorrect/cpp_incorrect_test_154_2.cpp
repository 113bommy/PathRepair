#include <bits/stdc++.h>
using namespace std;
int dizi[3];
int solve(int x, int y, int z) {
  set<int> s;
  s.insert(x);
  s.insert(y);
  s.insert(z);
  dizi[0] = x;
  dizi[1] = y;
  dizi[2] = z;
  if (s.size() == 3) {
    int mx = 0;
    for (int i = 0; i < 2; i++) {
      if (dizi[mx] < dizi[i + 1]) {
        mx = i + 1;
      }
    }
    int a = dizi[0] + dizi[1] + dizi[2];
    if (dizi[mx] * 2 == a) {
      cout << "yes";
    } else {
      cout << "no";
    }
  } else if (s.size() == 2) {
    int farkli;
    if (x == y)
      farkli = z;
    else if (x == z)
      farkli = y;
    else
      farkli = z;
    if (farkli % 2 == 0) {
      cout << "yes";
    } else {
      cout << "no";
    }
  } else {
    if (x % 2 == 0)
      cout << "yes";
    else
      cout << "no";
  }
  cout << endl;
  return 0;
}
int main() {
  int n, a, b, c;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    solve(a, b, c);
  }
}
