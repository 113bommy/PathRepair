#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void omae_wa_mou_shindeiru(int tc) {
  long long n;
  cin >> n;
  vector<long long> v(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  long long low = 1, high = 1e9;
  while (low < high) {
    long long mid = (low + high + 1) / 2;
    array<long long, 3> pending = {0, 0, 0};
    vector<long long> temp = v;
    bool flag = 1;
    for (int i = n - 1; i >= 2; i--) {
      long long extra = min(pending[0] + pending[1] + v[i] - mid, v[i]);
      if (extra >= 0) {
        temp[i] = v[i] + pending[0] + pending[1] - extra;
        if (temp[i] < mid) flag = 0;
        pending[0] = extra / 3;
        pending[1] = pending[2];
        pending[2] = (extra / 3) * 2;
      }
      if (temp[i] < mid) flag = 0;
    }
    if (temp[0] + pending[2] < mid or temp[1] + pending[1] + pending[0] < mid)
      flag = 0;
    if (flag)
      low = mid;
    else
      high = mid - 1;
  }
  cout << low << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i < tc + 1; i++) {
    omae_wa_mou_shindeiru(i);
  }
}
