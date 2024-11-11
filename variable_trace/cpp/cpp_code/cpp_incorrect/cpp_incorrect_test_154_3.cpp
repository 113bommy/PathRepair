#include <bits/stdc++.h>
using namespace std;
bool simple(int a, int b, int c) {
  if (a == b && c % 2 == 0) return true;
  if (c == b && a % 2 == 0) return true;
  if (a == c && b % 2 == 0) return true;
  return false;
}
bool tryBreaK(int a, int b, int c) {
  if (abs(a - b) == c) return true;
  if (abs(b - c) == a) return true;
  if (abs(a - c) == b) return true;
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (simple(a, b, c) || tryBreaK(a, b, c)) {
      cout << "YES" << endl;
      break;
    }
    cout << "NO" << endl;
  }
}
