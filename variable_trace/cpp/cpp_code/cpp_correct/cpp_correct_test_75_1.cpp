#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2e5 + 10;
int n, m, t;
int a[SIZE];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 1, r = n;
  int cnt1 = 1, cnt2 = 1;
  while (l < n && a[l] < a[l + 1]) l++, cnt1++;
  while (r > 1 && a[r] < a[r - 1]) r--, cnt2++;
  if (cnt1 % 2 || cnt2 % 2)
    cout << "Alice" << endl;
  else
    cout << "Bob" << endl;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
