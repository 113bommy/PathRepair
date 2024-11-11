#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
char str[3025];
long long int dp[3025][3025];
int t;
int main() {
  cin >> t;
  while (t--) {
    int arr[100];
    for (int i = 1; i <= 7; i++) {
      cin >> arr[i];
    }
    cout << arr[1] << " " << arr[2] << " " << (arr[7] - arr[1] - arr[2])
         << "\n";
  }
}
