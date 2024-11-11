#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC Optimization("unroll-loops")
#pragma GCC target("avx2")
void in(vector<long long> &v) {
  for (long long i = 0; i <= v.size() - 1; i++) cin >> v[i];
}
void out(vector<long long> v) {
  for (long long i = 0; i <= v.size() - 1; i++) cout << v[i] << ' ';
  cout << "\n";
}
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 2; i <= n + 1; i++) cout << i << " ";
    cout << "\n";
  }
}
