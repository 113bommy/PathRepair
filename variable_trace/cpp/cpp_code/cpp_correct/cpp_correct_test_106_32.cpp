#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6 + 5;
long long n, k, a[N], res;
void solo() {
  cin >> n;
  for (int i = 1; i <= n; i++) cout << i + 1 << " ";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solo();
    cout << endl;
  }
  cerr << "\n" << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms";
}
