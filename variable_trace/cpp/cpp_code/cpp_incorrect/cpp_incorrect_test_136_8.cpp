#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1000000007;
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
unsigned long long power(unsigned long long x, long long int y,
                         long long int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long modInverse(unsigned long long n, long long int p) {
  return power(n, p - 2, p);
}
unsigned long long nCrModPFermat(unsigned long long n, long long int r,
                                 long long int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  unsigned long long fac[n + 1];
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
long long int find_set(long long int i, vector<long long int> &parent) {
  if (parent[i] == -1) {
    return i;
  } else {
    parent[i] = find_set(parent[i], parent);
    return parent[i];
  }
}
void union_set(long long int i, long long int j, vector<long long int> &parent,
               vector<long long int> &rank) {
  long long int s1 = find_set(i, parent);
  long long int s2 = find_set(j, parent);
  if (s1 != s2) {
    if (rank[s1] > rank[s2]) {
      parent[s2] = s1;
      rank[s1] += rank[s2];
    } else {
      parent[s1] = s2;
      rank[s2] += rank[s1];
    }
  } else {
    return;
  }
}
void solve() {
  long long int n, i, j;
  cin >> n;
  long long int arr[n];
  long long int sum = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  if ((2 * sum) % (n * (n + 1)) != 0) {
    cout << "NO" << endl;
    return;
  }
  long long int val = (2 * sum) / (n * (n + 1));
  if (val < n) {
    cout << "NO" << endl;
    return;
  }
  vector<long long int> a(n);
  for (i = 0; i < n; i++) {
    long long int val1 = arr[i];
    long long int val2 = arr[(i - 1 + n) % (n)];
    if ((val - val1 + val2) > 0 && (val - val1 + val2) % n != 0) {
      cout << "NO" << endl;
      return;
    }
    a[i] = (val - val1 + val2) / n;
  }
  cout << "YES" << endl;
  for (i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
}
