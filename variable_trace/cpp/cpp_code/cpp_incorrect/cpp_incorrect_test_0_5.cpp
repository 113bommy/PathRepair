#include <bits/stdc++.h>
using namespace std;
int t, n, m;
pair<string, int> p[1000001];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j < m; j += 2) s[j] = 155 - s[j];
    p[i] = {s, i};
  }
  sort(p, p + n);
  for (int i = 1; i <= n; i++) cout << p[i].second << ' ';
}
