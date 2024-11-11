#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      v.push_back(k);
    }
    sort(v.begin(), v.end());
    int temp = n / 2;
    int i = 0, j = 1;
    while (j <= temp) {
      cout << v[j] << " " << v[i] << endl;
      j++;
    }
  }
}
