#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int main() {
  int T;
  int x1, p1, x2, p2;
  cin >> T;
  string res;
  while (T--) {
    cin >> x1 >> p1 >> x2 >> p2;
    if (p2 - p1 > 6) {
      res += '<';
      continue;
    }
    if (p1 - p2 > 6) {
      res += '>';
      continue;
    }
    char s1[N] = "\0", s2[N] = "\0";
    int t1 = x1, t2 = x2;
    int cnt1 = 0, cnt2 = 0;
    while (t1) {
      cnt1++;
      t1 /= 10;
    }
    while (t2) {
      cnt2++;
      t2 /= 10;
    }
    int idx1 = 0, idx2 = 0;
    for (int i = cnt1 - 1; i >= 0; i--) {
      int tt = (x1 / pow(10, i));
      tt %= 10;
      s1[idx1++] = tt + '0';
    }
    for (int i = cnt2 - 1; i >= 0; i--) {
      int tt = x2 / pow(10, i);
      tt %= 10;
      s2[idx2++] = tt + '0';
    }
    if (idx1 + p1 < idx2 + p2) {
      res += '<';
      continue;
    }
    if (idx1 + p1 > idx2 + p2) {
      res += '>';
      continue;
    }
    if (cnt1 < cnt2) {
      cnt1 = cnt2;
      for (int i = idx1; i < idx2; i++) s1[i] = '0';
    }
    if (cnt1 > cnt2)
      for (int i = idx2; i < idx1; i++) s2[i] = '0';
    for (int i = 0; i < cnt1; i++) {
      if (s1[i] < s2[i]) {
        res += '<';
        break;
      }
      if (s1[i] > s2[i]) {
        res += '>';
        break;
      }
      if (i == cnt1 - 1) res += '=';
    }
  }
  for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
  return 0;
}
