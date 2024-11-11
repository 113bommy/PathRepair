#include <bits/stdc++.h>
using namespace std;
bool isPoss(vector<long long> &diff, long long x, long long h) {
  long long tot = 0;
  for (int i = 0; i < diff.size(); i++) {
    if (diff[i] > x) {
      tot += x;
    } else {
      tot += diff[i];
    }
  }
  tot += x;
  if (tot >= h) {
    return true;
  } else {
    return false;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, h;
    cin >> n >> h;
    vector<long long> vec(n);
    for (auto &i : vec) {
      cin >> i;
    }
    if (n == 1) {
      cout << h << endl;
    } else {
      vector<long long> diff;
      for (int i = 1; i < n; i++) {
        diff.push_back(vec[i] - vec[i - 1]);
      }
      sort(diff.begin(), diff.end());
      long long l = 1;
      long long r = 1e10;
      long long mid;
      long long ans;
      while (l < r) {
        mid = l + (r - l) / 2;
        if (isPoss(diff, mid, h)) {
          r = mid;
          ans = mid;
        } else {
          l = mid + 1;
        }
      }
      cout << ans << endl;
    }
  }
}
