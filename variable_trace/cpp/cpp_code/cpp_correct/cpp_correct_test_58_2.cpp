#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  while (k--) {
    int n, f = 1;
    string sa, sb;
    cin >> n >> sa >> sb;
    for (int i = 0; i < n; i++)
      if ((sa[i] == '1') && (sb[i] == '1')) {
        f = 0;
        break;
      }
    if (f)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
