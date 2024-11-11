#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int arr[7];
    for (int i = 0; i < 7; i++) {
      cin >> arr[i];
    }
    arr[6] = arr[6] - arr[0] - arr[1];
    cout << arr[0] << " " << arr[1] << " " << arr[6] << endl;
  }
}
