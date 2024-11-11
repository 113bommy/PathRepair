#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v;
    int op = n;
    while (op--) {
      long long num;
      cin >> num;
      v.push_back(num);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n / 2; i++) {
      cout << v[i] << " " << v[0] << endl;
    }
  }
  return 0;
}
