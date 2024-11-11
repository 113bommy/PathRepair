#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v[i] = pow(10LL, x);
    }
    sort(v.begin(), v.end());
    vector<long long> diff;
    for (long long i = 1; i < n; i++) {
      diff.push_back(v[i] / v[i - 1] - 1);
    }
    long long sum = 0, idx = -1, sum1 = 0;
    for (long long i = 0; i < (long long)diff.size(); i++) {
      sum += diff[i];
      if (sum > k) {
        sum1 = sum - diff[i];
        idx = i;
        break;
      }
    }
    if (idx == -1) {
      long long rem = (k - sum + 1) * (*prev(v.end()));
      if ((long long)v.size() == 1) {
        cout << rem << "\n";
      } else {
        cout << rem + (*prev(v.end())) - 1 << "\n";
      }
    } else {
      long long rem = (k - sum1 + 1) * v[idx];
      cout << rem + v[idx] - 1 << "\n";
    }
  }
}
