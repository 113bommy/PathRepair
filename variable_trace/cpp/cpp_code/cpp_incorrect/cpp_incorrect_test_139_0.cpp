#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  cin.ignore();
  while (tc--) {
    string st;
    getline(cin, st);
    if (st.size() % 2 != 0) {
      cout << "NO" << endl;
    } else {
      int ck = 0;
      for (int i = 0; i < st.size() / 2; i++) {
        if (st[i] != st[st.size() - i - 2]) {
          ck = 1;
          break;
        }
      }
      if (ck == 1) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
  return 0;
}
