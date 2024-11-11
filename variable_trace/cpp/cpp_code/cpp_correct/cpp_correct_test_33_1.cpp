#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int MOD = 1e9 + 7;
int binarySearch(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  } else {
    return -1;
  }
}
ll power(ll x, ll y) {
  ll res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
const int N = 100000;
int arr[N];
int mn[512];
void solve() {
  int n;
  cin >> n;
  for (int i = (0); i < (n); i++) {
    cin >> arr[i];
  }
  mn[0] = -1;
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (512); j++) {
      if (mn[j] != MOD && arr[i] > mn[j]) {
        int y = arr[i] ^ j;
        mn[y] = min(mn[y], arr[i]);
      }
    }
  }
  int ans = 0;
  vector<int> val;
  for (int i = (0); i < (512); i++) {
    if (mn[i] != MOD) {
      ans++;
      val.push_back(i);
    }
  }
  cout << ans << '\n';
  for (int i = (0); i < (ans); i++) {
    cout << val[i] << " ";
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  for (int i = (0); i < (512); i++) {
    mn[i] = MOD;
  }
  while (t--) {
    solve();
  }
  return 0;
}
