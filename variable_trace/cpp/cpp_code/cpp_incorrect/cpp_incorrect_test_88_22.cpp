#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    bool good = 0;
    vector<int> a(N);
    for (int &i : a) cin >> i;
    for (int i = 0; i + 1 < N; i++) {
      if (a[i] > a[i + 1]) good = 1;
    }
    if (!good and N % 2)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
