#include <bits/stdc++.h>
using namespace std;
int N = 1000000007;
int solve() {
  int n, k;
  cin >> n;
  cin >> k;
  long long int pow = 1;
  long long int sum = 0;
  while (k > 0) {
    sum = ((k % 2) * pow + sum) % N;
    k /= 2;
    pow = (pow * n) % N;
  }
  return (sum + N) % N;
}
int main() {
  int q;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> q;
  while (q--) {
    cout << solve() << "\n";
  }
  return 0;
}
