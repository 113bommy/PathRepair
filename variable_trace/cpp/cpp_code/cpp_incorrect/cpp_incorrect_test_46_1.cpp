#include <bits/stdc++.h>
using namespace std;
long long funMax(vector<long long>& a) {
  long long m = a[0];
  for (long long i = 1; i < a.size(); i++) {
    if (m < a[i]) m = a[i];
  }
  return m;
}
void solve() {
  long long n, cnt = 0;
  cin >> n;
  vector<long long> a;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a.push_back(x);
  }
  long long k = funMax(a);
  if (a[n - 1] == k)
    cout << 0 << "\n";
  else {
    long long i = n - 2, j = n - 1;
    while ((i >= 0 && j >= 0)) {
      if (a[j] == k)
        break;
      else if (j > 0 && (a[j] < a[i])) {
        cnt++;
        i--;
        j--;
      } else
        i--;
    }
    cout << cnt << "\n";
  }
}
int main() {
  long long T;
  cin >> T;
  while (T--) solve();
  return 0;
}
