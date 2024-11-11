#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    long long int l;
    cin >> l;
    long long int arr[l];
    for (long long int i = 0; i < l; i++) {
      arr[0] = 2;
      arr[1] = 3;
      arr[i] = i + 2;
    }
    for (long long int i = 0; i < l; i++) {
      cout << arr[i] << " ";
    }
  }
}
