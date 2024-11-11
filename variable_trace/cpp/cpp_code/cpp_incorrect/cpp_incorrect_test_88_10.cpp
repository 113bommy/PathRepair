#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& x : nums) {
      cin >> x;
    }
    bool ans = n % 2 == 0;
    for (int i = 0; i < n - 1; ++i) {
      ans |= nums[i] > nums[i + 1];
    }
    int cnt = 0, cur = 0;
    for (int x : nums) {
      if (x > cur) {
        cur = x;
        cnt++;
      }
    }
    ans |= cnt % 2 == 0;
    cout << (ans ? "YES" : "NO") << '\n';
  }
}
