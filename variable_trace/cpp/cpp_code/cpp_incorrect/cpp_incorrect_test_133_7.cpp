#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int main() {
  clock_t clk = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 0;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string arr[n - 2];
    for (int i = 0; i < n - 2; i++) {
      cin >> arr[i];
    }
    string p = arr[0];
    p.erase(p.end() - 1);
    for (int i = 0; i < n - 3; i++) {
      if (arr[i][1] == arr[i + 1][0])
        p += arr[i][1];
      else {
        p += arr[i][1];
        p += arr[i + 1][0];
      }
      if (i == n - 4) p += arr[i][1];
    }
    if (n == 3) {
      p = arr[0];
      p += 'a';
    } else if (p.size() < n) {
      p += 'a';
    }
    cout << p << "\n";
  }
  cerr << '\n'
       << "Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC
       << '\n';
  return 0;
}
