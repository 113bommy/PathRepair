#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int getCases() {
  int cases = -1;
  enum InputType : int {
    SingleInput = 1,
    MultipleInput = 2,
    NotSet = 0,
  };
  InputType inputType = MultipleInput;
  if (inputType == SingleInput) {
    cases = 1;
  } else if (inputType == MultipleInput) {
    scanf("%d", &cases);
  } else {
    assert(false && "fix the function");
  }
  return cases;
}
int n;
int ar[105];
int big;
void Input() {
  big = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &ar[i]);
    big = max(big, ar[i]);
  }
}
int main() {
  int cases = getCases();
  while (cases--) {
    Input();
    int ans = INT_MAX;
    for (int a = 0; a <= 3; ++a) {
      for (int b = 0; b <= 3; ++b) {
        int c = (big - a - 2 * b + 2) / 3;
        int good = true;
        for (int i = 0; i < n; ++i) {
          int r = ceil((double)ar[i] / 3.0);
          if (ar[i] % 3 == 0) {
            if (c >= r) {
            } else if (c >= r - 1 && ((a >= 1 && b >= 1) || a >= 3)) {
            } else {
              good = false;
            }
          } else if (ar[i] % 3 == 1) {
            if (c >= r - 1 && a >= 1) {
            } else if (ar[i] > 3 && c >= r - 2 && b >= 2) {
            } else {
              good = false;
            }
          } else if (ar[i] % 3 == 2) {
            if (c >= r - 1 && (a >= 2 || b >= 1)) {
            } else {
              good = false;
            }
          }
        }
        if (good) {
          ans = min(ans, a + b + c);
        }
      }
    }
    printf("%d\n", ans);
  }
}
