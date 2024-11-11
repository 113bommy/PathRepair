#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void coutar(int a[], int n);
void cinar(int* a, int n);
void fun() {
  int n;
  cin >> n;
  int a[n][5];
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j];
    }
  }
  int u1 = 0, u2 = 0, c = 0;
  for (int e = 0; e < 4; e++) {
    for (int f = e + 1; f < 5; f++) {
      c = 0;
      u1 = 0;
      u2 = 0;
      for (int i = 0; i < n; i++) {
        if (a[i][e] == 1 && a[i][f] == 1) {
          c++;
        }
        if (a[i][e] == 0 && a[i][f] == 0) {
          u1++;
        }
        if (a[i][e] == 0 && a[i][f] == 1) {
          u2++;
        }
        if (a[i][e] == 0 && a[i][f] == 0) {
          continue;
        }
      }
      if (c + u1 + u2 >= n) {
        if (u1 + c >= n / 2) {
          if (u2 + c >= n / 2) {
            cout << "YES\n";
            return;
          }
        }
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    fun();
  }
}
void coutar(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
void cinar(int* a, int n) {
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
}
