#include <bits/stdc++.h>
using namespace std;
int func(int a, int b, int c) {
  int diff;
  a = a % 2;
  b = b % 2;
  c = c % 2;
  if (a == 0 && b == 0 && c == 0) diff = 0;
  if (a == 0 && b == 0 && c == 1) diff = 1;
  if (a == 0 && b == 1 && c == 0) diff = 0;
  if (a == 0 && b == 1 && c == 1) diff = 1;
  if (a == 1 && b == 0 && c == 0) diff = 1;
  if (a == 1 && b == 0 && c == 1) diff = 0;
  if (a == 1 && b == 1 && c == 0) diff = 1;
  if (a == 1 && b == 1 && c == 1) diff = 0;
  return diff;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int diff = func(a, b, c);
    cout << diff << "\n";
  }
}
