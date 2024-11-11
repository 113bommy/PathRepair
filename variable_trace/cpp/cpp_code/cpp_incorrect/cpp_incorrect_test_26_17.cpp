#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n;
    long long rez = 1;
    cin >> n;
    for (int j = 3; j <= 2 * n; j++) {
      rez *= j;
      rez %= 1000000007;
    }
    cout << rez;
  }
}
