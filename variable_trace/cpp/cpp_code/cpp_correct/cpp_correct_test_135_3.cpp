#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> a(n);
    long long int sum = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (k == 0) {
      cout << sum << endl;
    } else {
      sort(a.begin(), a.end());
      sum = 0;
      long long int cnt = 0;
      vector<long long int> temp;
      for (long long int i = 0; i < n; i++) {
        temp.push_back(a[i]);
      }
      for (long long int i = n - 1; i > 0; i = i - 2) {
        cnt++;
        sum += (temp[i - 1] / temp[i]);
        temp[i] = 0;
        temp[i - 1] = 0;
        if (cnt == k) {
          break;
        }
      }
      for (long long int i = 0; i < n; i++) {
        sum += temp[i];
      }
      long long int mx = INT_MAX;
      mx = min(mx, sum);
      temp.clear();
      cnt = 0;
      sum = 0;
      for (long long int i = 0; i < n; i++) {
        temp.push_back(a[i]);
      }
      long long int ind = n - 1 - k;
      for (long long int i = n - 1; i >= 0; i--) {
        cnt++;
        sum += (temp[ind] / temp[i]);
        temp[i] = 0;
        temp[ind] = 0;
        ind--;
        if (cnt == k) {
          break;
        }
      }
      for (long long int i = 0; i < n; i++) {
        sum += temp[i];
      }
      cout << min(mx, sum) << endl;
    }
  }
  return 0;
}
