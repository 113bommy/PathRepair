#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int arr[7];
    for (int i = 0; i < 7; i++) {
      cin >> arr[i];
    }
    vector<int> v;
    v.push_back(arr[0]);
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 7; j++) {
        if (arr[0] + arr[i] + arr[j] == arr[6]) {
          v.push_back(arr[i]);
          v.push_back(arr[j]);
          break;
        }
      }
    }
    cout << v[0] << " " << v[1] << " " << v[2] << endl;
  }
  return 0;
}
