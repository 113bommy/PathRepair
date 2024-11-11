#include <bits/stdc++.h>
using namespace std;
void solution() {
  long long int n, m, a, b, c, d, p, q, cnt = 0, ct = 0, sum = 0, ans = 0;
  cin >> n >> a;
  cin >> m >> b;
  p = n;
  q = m;
  string s1, s2;
  s1 = to_string(p);
  s2 = to_string(q);
  long long int sz1, sz2;
  sz1 = s1.size();
  sz2 = s2.size();
  long long int second = sz1, sss = sz2;
  sz1 += a;
  sz2 += b;
  if (sz1 > sz2)
    cout << "> " << endl;
  else if (sz1 < sz2)
    cout << "<" << endl;
  else {
    if (second > sss) {
      for (long long int i = 0; i < second - sss; i++) s2 += '0';
    } else {
      for (long long int i = 0; i < sss - second; i++) s1 += '0';
    }
    for (long long int i = 0; i < s1.size(); i++) {
      if (s1[i] > s2[i]) {
        cout << ">" << endl;
        return;
      } else if (s2[i] > s1[i]) {
        cout << "<" << endl;
        return;
      }
    }
    cout << "=" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
