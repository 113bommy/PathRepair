#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  string s;
  cin >> s;
  vector<pair<int, int>> arr1, arr2;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      arr1.push_back({arr[i], i});
    } else {
      arr2.push_back({arr[i], i});
    }
  }
  sort(arr1.begin(), arr1.end());
  sort(arr2.begin(), arr2.end());
  int tmp = n;
  vector<int> ans(n);
  for (auto itr : arr1) {
    ans[itr.second] = tmp--;
  }
  for (auto itr : arr2) {
    ans[itr.second] = tmp--;
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
