#include <bits/stdc++.h>
using namespace std;
template <typename T, typename M>
istream& operator>>(istream& in, pair<T, M>& pr) {
  in >> pr.first >> pr.second;
  return in;
}
template <typename T, typename M>
ostream& operator<<(ostream& out, const pair<T, M>& pr) {
  out << pr.first << ' ' << pr.second;
  return out;
}
template <typename T, typename M>
pair<T, M> operator+(const pair<T, M>& p1, const pair<T, M>& p2) {
  return make_pair(p1.first + p2.first, p1.second + p2.second);
}
bool prostoechislo(unsigned long long k) {
  for (unsigned long long j = 2; j * j <= k; j++)
    if (k % j == 0) return 0;
  return 1;
}
int stepen(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0)
    return stepen(a, b / 2) * stepen(a, b / 2);
  else
    return a * stepen(a, b - 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long x, n;
    cin >> x >> n;
    long long n1 = n;
    long long n2 = n;
    if (n % 4 == 0) {
      cout << x << "\n";
      continue;
    }
    if (n % 4 == 1) {
      if (x % 2 == 0)
        cout << x - n << "\n";
      else
        cout << x + n << "\n";
      continue;
    }
    if (n % 4 == 2) {
      if (x % 2 == 0)
        cout << x + 1 << "\n";
      else
        cout << x - 1;
    }
    if (n % 4 == 3) {
      if (x % 2 == 0)
        cout << x + n + 1 << "\n";
      else
        cout << x - n - 1 << "\n";
    }
  }
}
