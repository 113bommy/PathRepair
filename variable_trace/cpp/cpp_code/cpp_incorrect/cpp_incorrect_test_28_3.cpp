#include <bits/stdc++.h>
using namespace std;
void minz(long long &A, long long B) {
  if (A > B) A = B;
  return;
}
void maxz(long long &A, long long B) {
  if (A < B) A = B;
  return;
}
const int maxn{(int)(1e3 + 2911)};
const int MOD{(int)(123457)};
void Solve_case() {
  long long a, b, c;
  cin >> a >> b >> c;
  a += b + c;
  cout << (a % 2) << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int sub;
  int T_T = 1;
  cin >> T_T;
  while (T_T--) {
    Solve_case();
  }
  return 0;
}
