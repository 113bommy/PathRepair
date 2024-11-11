#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  while (cin >> n) {
    vi a(n);
    for (auto &x : a) {
      cin >> x;
    }
    vector<bool> wf(n), wb(n);
    wb[0] = true;
    for (int i = 1; i < n; i++) {
      if (a[i - 1] > a[i]) {
        wb[i] = !wb[i - 1];
      } else {
        wb[i] = true;
      }
    }
    wf[n - 1] = true;
    for (int i = n - 2; i >= 0; i--) {
      if (a[i + 1] > a[i]) {
        wf[i] = !wf[i + 1];
      } else {
        wf[i] = true;
      }
    }
    int i = 0, j = n - 1, turn = 0, last = -1;
    while (i <= j) {
      if (a[i] < last && a[j] < last) {
        break;
      }
      if (a[i] < last) {
        if (wb[j]) {
          turn ^= 1;
        }
        break;
      }
      if (a[j] < last) {
        if (wf[i]) {
          turn ^= 1;
        }
        break;
      }
      if (a[i] < a[j]) {
        if (wb[j]) {
          turn ^= 1;
          break;
        } else {
          last = a[i++];
        }
      } else if (a[i] > a[j]) {
        if (wf[i]) {
          turn ^= 1;
          break;
        } else {
          last = a[j--];
        }
      } else {
        if (wf[i] || wb[j]) {
          turn ^= 1;
        }
        break;
      }
      turn ^= 1;
    }
    if (turn == 1) {
      cout << "Alice" << '\n';
    } else {
      cout << "Bob" << '\n';
    }
  }
  return 0;
}
