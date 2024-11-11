#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n];
    for (long long int i = 0; i < n; i++) cin >> arr[i];
    if (n % 2 == 0) {
      cout << "YES"
           << "\n";
      continue;
    }
    long long int check = 0;
    for (long long int i = 1; i < n; i++) {
      if (arr[i - 1] > arr[i]) {
        cout << "YES"
             << "\n";
        check++;
        break;
      }
    }
    if (check) continue;
    cout << "NO"
         << "\n";
  }
  return 0;
}
