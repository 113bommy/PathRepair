#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void solve() {
  long long a, s, tempa, temp2;
  cin >> a >> s;
  if (a == s) {
    cout << "0";
    return;
  }
  tempa = a;
  temp2 = s;
  vector<int> num1, sum;
  while (tempa > 0) {
    num1.push_back(tempa % 10);
    tempa = tempa / 10;
  }
  while (temp2 > 0) {
    sum.push_back(temp2 % 10);
    temp2 = temp2 / 10;
  }
  int c = num1.size();
  if (num1.size() < sum.size()) {
    for (int i = 0; i < sum.size() - num1.size(); i++) num1.push_back(0);
  }
  vector<long long> ans;
  int k = 0;
  for (int i = 0; i < c; i++) {
    if (k >= sum.size()) {
      cout << "-1";
      return;
    }
    if (num1[i] <= sum[k]) {
      ans.push_back(sum[k] - num1[i]);
      k++;
    } else {
      if (k + 1 >= sum.size()) {
        cout << "-1";
        return;
      }
      int x = (sum[k + 1] * 10 + sum[k]);
      if (x - num1[i] > 9) {
        cout << "-1";
        return;
      }
      ans.push_back(x - num1[i]);
      k += 2;
    }
  }
  if (k < sum.size()) {
    for (int i = k; i < sum.size(); i++) {
      ans.push_back(sum[i]);
    }
  }
  reverse(ans.begin(), ans.end());
  int itr = 0;
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] != 0) {
      itr = i;
      break;
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] < 0) {
      cout << "-1";
      return;
    }
  }
  long long num = 0;
  for (int i = itr; i < ans.size(); i++) {
    num = num * 10 + ans[i];
  }
  if (num > s) {
    cout << "-1";
    return;
  }
  for (int i = itr; i < ans.size(); i++) cout << ans[i];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
