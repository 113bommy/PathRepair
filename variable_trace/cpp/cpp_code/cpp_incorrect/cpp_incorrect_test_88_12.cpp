#include <bits/stdc++.h>
using namespace std;
string to_upper(string &a) {
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A';
  return a;
}
string to_lower(string &a) {
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A';
  return a;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
void dsc() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  if (n % 2 == 0) {
    cout << "YES\n";
    return;
  }
  int x = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) x++;
  }
  if (x == 0)
    cout << "NO\n";
  else
    cout << "YES\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) dsc();
}
