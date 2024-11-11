#include <bits/stdc++.h>
using namespace std;
int n, arr[200005], b1;
vector<int> v1, v2;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i == 0)
      v1.push_back(arr[i]);
    else {
      if (arr[i] > arr[i - 1] && b1 == 0)
        v1.push_back(arr[i]);
      else
        b1 = 1;
    }
  }
  b1 = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1)
      v2.push_back(arr[i]);
    else {
      if (arr[i] > arr[i + 1] && b1 == 0)
        v2.push_back(arr[i]);
      else
        break;
    }
  }
  int l = 0, r = 0, x = 0;
  while (l < v1.size() && r < v2.size()) {
    if (x == 0) {
      if (v1[l] >= v2[r] && (v1.size() - l) % 2 == 1 ||
          v2[r] >= v1[l] && (v2.size() - r) % 2 == 1) {
        cout << "Alice";
        return 0;
      }
      if (v1[l] == v2[r]) {
        cout << "Bob";
        return 0;
      }
      x = 1;
      if (v1[l] > v2[r])
        r += 1;
      else
        l += 1;
    } else {
      if (v1[l] >= v2[r] && (v1.size() - l) % 2 == 0 ||
          v2[r] >= v1[l] && (v2.size() - r) % 2 == 0) {
        cout << "Bob";
        return 0;
      }
      if (v1[l] == v2[r]) {
        cout << "Alice";
        return 0;
      }
      x = 0;
      if (v1[l] > v2[r])
        r += 1;
      else
        l += 1;
    }
  }
  if (x == 0) {
    if (l == v1.size() && (v2.size() - r) % 2 == 1 ||
        r == v2.size() && (v1.size() - l) % 2 == 1) {
      cout << "Alice";
      return 0;
    }
    cout << "Bob";
  } else {
    if (l == v1.size() && (v2.size() - r) % 2 == 0 ||
        r == v2.size() && (v1.size() - l) % 2 == 0) {
      cout << "Bob";
      return 0;
    }
    cout << "Alice";
  }
  return 0;
}
