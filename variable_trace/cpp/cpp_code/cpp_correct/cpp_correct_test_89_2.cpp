#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n;
int a[N];
bool check(int x) {
  for (int j = x + 1; j >= 2; j--) {
    if (a[x] % j) return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool succ = true;
    for (int i = 1; i <= n; i++) {
      if (check(i) == false) {
        succ = false;
        break;
      }
    }
    if (succ)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
