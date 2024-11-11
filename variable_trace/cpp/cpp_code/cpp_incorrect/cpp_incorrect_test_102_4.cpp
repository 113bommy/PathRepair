#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int num1 = 0;
    int num2 = 0;
    int l = s.length();
    int maxn1 = 0;
    int minn1 = 1e7;
    int maxn2 = 0;
    int minn2 = 1e7;
    int flag = 0;
    for (int i = 0; i < l; i++) {
      if (s[i] == 'U')
        num2++;
      else if (s[i] == 'D')
        num2--;
      else if (s[i] == 'L')
        num1--;
      else
        num1++;
      if (num1 > maxn1) maxn1 = num1;
      if (num1 < minn1) minn1 = num1;
      if (num2 > maxn2) maxn2 = num2;
      if (num2 < minn2) minn2 = num2;
      if (maxn1 - minn1 >= m || maxn1 >= m || abs(minn1) >= m) {
        flag = i;
        break;
      }
      if (maxn2 - minn2 >= n || maxn2 >= n || abs(minn2) >= n) {
        flag = i;
        break;
      }
      if (i == l - 1) flag = i;
    }
    num1 = 0;
    num2 = 0;
    maxn1 = 0;
    minn1 = 1e7;
    maxn2 = 0;
    minn2 = 1e7;
    for (int i = 0; i <= flag; i++) {
      if (s[i] == 'U')
        num2++;
      else if (s[i] == 'D')
        num2--;
      else if (s[i] == 'L')
        num1--;
      else
        num1++;
      if (num1 > maxn1) maxn1 = num1;
      if (num1 < minn1) minn1 = num1;
      if (num2 > maxn2) maxn2 = num2;
      if (num2 < minn2) minn2 = num2;
    }
    if (flag == 0) {
      cout << n << ' ' << m << endl;
    } else
      cout << maxn2 + 1 << ' ' << m - maxn1 << endl;
  }
}
