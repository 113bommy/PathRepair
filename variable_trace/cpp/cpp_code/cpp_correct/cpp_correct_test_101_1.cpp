#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b;
    vector<int> r;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      char ch = s[i];
      if (ch == 'B') {
        b.push_back(a[i]);
      } else {
        r.push_back(a[i]);
      }
    }
    bool flg = true;
    sort(b.begin(), b.end());
    sort(r.begin(), r.end());
    cout << "\n";
    int i = 0, j = 0, c = 1;
    while (i < b.size()) {
      if (b[i] < c) {
        flg = false;
        cout << "NO";
        break;
      }
      i++;
      c++;
    }
    while (j < r.size() && flg) {
      if (r[j] > c) {
        flg = false;
        cout << "NO";
        break;
      }
      j++;
      c++;
    }
    if (flg) {
      cout << "YES";
    }
  }
}
