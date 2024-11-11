#include <bits/stdc++.h>
using namespace std;
void ha() { printf("YES\n"); }
void na() { printf("NO\n"); }
long long power(long long a, long long b) {
  long long c, d;
  if (b == 1) {
    return a % 1000000007;
  } else if (b % 2 == 0) {
    c = power(a, b / 2);
    return (c * c) % 1000000007;
  } else {
    c = power(a, b / 2);
    d = (c * c) % 1000000007;
    d = (d * a) % 1000000007;
    return d;
  }
}
int absolute(int a) {
  if (a >= 0) {
    return a;
  } else {
    return (a * (-1));
  }
}
long long absolute(long long a) {
  if (a >= 0) {
    return a;
  } else {
    return (a * (-1));
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    string a;
    cin >> a;
    int n = a.length();
    if (a[0] != a[n - 1]) {
      a[0] = a[n - 1];
      cout << a << endl;
    } else {
      cout << a << endl;
    }
  }
  return 0;
}
