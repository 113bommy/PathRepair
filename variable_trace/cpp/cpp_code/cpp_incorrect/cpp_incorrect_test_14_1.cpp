#include <bits/stdc++.h>
using namespace std;
int main() {
  int _t;
  cin >> _t;
  for (int _ = 0; _ < (_t); ++_) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < (n); ++i) {
      scanf("%d", &a[i]);
    }
    vector<int> l, r, cnt;
    for (int i = 0; i < (n); ++i) {
      int mini = 1000000001, ind = -1;
      for (int j = i; j < n; j++) {
        if (mini > a[j]) {
          mini = a[j];
          ind = j;
        }
      }
      if (ind == i) continue;
      l.push_back(i);
      r.push_back(ind);
      cnt.push_back(r.back() - l.back());
      for (int j = 0; j < (cnt.back()); ++j) {
        int t = a[i];
        for (int k = 0; k < (cnt.back() - 1); ++k) {
          a[i + k] = a[i + k + 1];
        }
        a[r.back()] = t;
      }
    }
    cout << l.size() << endl;
    for (int i = 0; i < (l.size()); ++i) {
      printf("%d %d %d\n", l[i] + 1, r[i] + 1, cnt[i]);
    }
  }
  return 0;
}
