#include <bits/stdc++.h>
using namespace std;
int cubeta[1000];
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      cubeta[s[i]]++;
    }
    if (cubeta['A'] == 0) {
      if (cubeta['B'] == cubeta['C']) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else if (cubeta['C'] == 0) {
      if (cubeta['B'] == cubeta['A']) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else if (cubeta['B'] == 0) {
      cout << "NO\n";
    } else {
      if (cubeta['A'] <= cubeta['B'] &&
          cubeta['B'] - cubeta['A'] == cubeta['C']) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
    cubeta['A'] = 0;
    cubeta['B'] = 0;
    cubeta['C'] = 0;
  }
  return 0;
}
