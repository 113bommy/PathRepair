#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, cnt = 0;
  cin >> n;
  for (long long i = 2; i <= sqrt(n); i++) {
    long long int temp[n];
    if ((i * i * i) <= n) cnt++;
  }
  cout << cnt + 1 << endl;
}
void opti() {
  long long int n;
  cin >> n;
  set<int> a;
  for (int i = 1; i * i <= n; i++) {
    a.insert(i * i);
  }
  for (int i = 1; i * i * i <= n; i++) {
    a.insert(i * i * i);
  }
  cout << a.size();
}
int main() {
  int t;
  cin >> t;
  while (t--) opti();
  return 0;
}
