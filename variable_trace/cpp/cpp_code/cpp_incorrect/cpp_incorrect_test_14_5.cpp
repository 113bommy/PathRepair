#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int mp(long long int a, long long int b) { return abs(a - b) / 2; }
void readFile() {}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int a[n], temp[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      temp[i] = a[i];
    }
    sort(temp, temp + n);
    int ans = 0;
    vector<vector<int>> v;
    int k = 0;
    int t1 = 0, t2 = 0;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
      if (temp[i] != a[i]) {
        ans++;
        l = i;
        for (int j = i; j < n; j++) {
          if (a[j] == temp[i]) {
            r = j;
            break;
          }
        }
        t2 = temp[i];
        for (int j = i; j < r + 1; j++) {
          t1 = a[j];
          a[j] = t2;
          t2 = t1;
        }
        v.push_back({l + 1, r + 1, 1});
        k++;
      }
    }
    cout << ans;
    cout << "\n";
    ;
    for (int i = 0; i < k; i++) {
      cout << v[i][0] << " " << v[i][1] << " " << v[i][2];
      cout << "\n";
    }
  }
  return 0;
}
