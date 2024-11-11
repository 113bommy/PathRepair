#include <bits/stdc++.h>
using namespace std;
long long solve(long long n, string str1, string str2) {
  long long t1 = 0, t2 = 0;
  for (long long i = 0; i < n; i++) {
    if (str1[i] != str2[i]) {
      if (str1[i] == '1')
        t1++;
      else
        t2++;
    }
  }
  if (t1 != t2)
    return -1;
  else
    return 2 * t1;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    string str1, str2;
    cin >> n;
    cin >> str1 >> str2;
    long long a1 = solve(n, str1, str2);
    long long ind = -1;
    for (long long i = 0; i < n; i++) {
      if (str1[i] == '1' && str2[i] == '1') {
        ind = i;
        break;
      }
    }
    long long a2 = -1;
    string temp = str1;
    if (ind != -1) {
      for (long long i = 0; i < n; i++) {
        if (str1[i] == '1' && i != ind)
          str1[i] = '0';
        else if (str1[i] == '0')
          str1[i] = '1';
      }
      a2 = solve(n, str1, str2);
    }
    long long a3 = -1;
    str1 = temp;
    long long ind2 = -1;
    for (long long i = 0; i < n; i++) {
      if (str1[i] == '1' && str2[i] == '0') {
        ind2 = i;
        break;
      }
    }
    if (ind2 != -1) {
      for (long long i = 0; i < n; i++) {
        if (str1[i] == '1' && i != ind)
          str1[i] = '0';
        else if (str1[i] == '0')
          str1[i] = '1';
      }
      a3 = solve(n, str1, str2);
    }
    if (a1 == -1 && a2 == -1 && a3 == -1) {
      cout << "-1" << endl;
    } else {
      if (a1 == -1 && a2 == -1)
        cout << (a3 + 1) << endl;
      else if (a1 == -1 && a3 == -1)
        cout << (a2 + 1) << endl;
      else if (a2 == -1 && a3 == -1)
        cout << a1 << endl;
      else if (a1 == -1)
        cout << min(a2 + 1, a3 + 1) << endl;
      else if (a2 == -1)
        cout << min(a1, a3 + 1) << endl;
      else if (a3 == -1)
        cout << min(a1, a2 + 1) << endl;
      else {
        long long b = min(a2 + 1, a3 + 1);
        long long ans = min(b, a1);
        cout << ans << endl;
      }
    }
  }
  return 0;
}
