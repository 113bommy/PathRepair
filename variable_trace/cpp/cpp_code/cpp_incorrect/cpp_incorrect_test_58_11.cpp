#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    string h = "YES";
    for (int i = 0; i < n; i++) {
      if (a[i] == '1' && b[i] == '1') {
        h = "NO";
        break;
      }
    }
    cout << h;
  }
}
