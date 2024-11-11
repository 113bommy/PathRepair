#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
void matrix(vector<vector<char> > &v, int r, int c, int row, int col, int k) {
  int ls = -1, rs = -1, i = row, j = col, mn;
  while (i >= 0 and j >= 0 and v[i][j] != '.') {
    ls++;
    i--;
    j--;
  }
  i = row, j = col;
  while (i >= 0 and j < c and v[i][j] != '.') {
    rs++;
    i--;
    j++;
  }
  mn = min(ls, rs);
  if (mn >= k) {
    ls = -1, rs = -1;
    i = row, j = col;
    while (i >= 0 and j >= 0 and v[i][j] != '.' and ls < mn) {
      v[i][j] = '$';
      i--;
      j--;
      ls++;
    }
    i = row, j = col;
    while (i >= 0 and j < c and v[i][j] != '.' and rs < mn) {
      v[i][j] = '$';
      i--;
      j++;
      rs++;
    }
  }
  return;
}
void solve() {
  char temp;
  bool ans = 1;
  int r, c, d;
  cin >> r >> c >> d;
  vector<vector<char> > v(r, vector<char>(c));
  for (long long i = 0; i < r; i++)
    for (long long j = 0; j < c; j++) {
      cin >> temp;
      v[i][j] = temp;
    }
  for (long long i = d; i < r; i++) {
    for (long long j = 0; j < c; j++)
      if (v[i][j] != '.') matrix(v, r, c, i, j, d);
  }
  for (long long i = 0; i < r; i++)
    for (long long j = 0; j < c; j++)
      if (v[i][j] == '*') {
        ans = 0;
        break;
      }
  ans ? cout << "YES" : cout << "NO";
  cout << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
