#include <bits/stdc++.h>
using namespace std;
void yn(bool b1) { cout << (b1 ? "YES\n" : "NO\n"); }
long long fact1(long long m1) {
  return m1 == 0 || m1 == 1 ? 1 : m1 * fact1(m1 - 1);
}
bool sbs(const pair<long long, long long> &pa1,
         const pair<long long, long long> &pa2) {
  return (pa1.second < pa2.second);
}
long long pow1(long long m1, long long m2) {
  if (!m2)
    return 1;
  else if (!(m2 % 2))
    return pow1(m1, m2 / 2) * pow1(m1, m2 / 2);
  else
    return m1 * pow1(m1, m2 / 2) * pow1(m1, m2 / 2);
}
long long minl(long long m1, ...) {
  long long mini = INT64_MAX;
  va_list nums;
  va_start(nums, m1);
  for (long long i = 0; i < m1; i++) mini = min(mini, va_arg(nums, long long));
  return mini;
}
long long maxl(long long m1, ...) {
  long long maxi = INT64_MIN;
  va_list nums;
  va_start(nums, m1);
  for (long long i = 0; i < m1; i++) maxi = max(maxi, va_arg(nums, long long));
  return maxi;
}
vector<bool> sieveOfEratosthenes(long long m1) {
  vector<bool> res(m1 + 1, 1);
  for (long long i = 2; i < sqrt(m1) + 1; i++) {
    if (res[i])
      for (long long j = i * i; j < m1 + 1; j++) {
        res[j] = 0;
        j += i - 1;
      }
  }
  return res;
}
void solution() {
  string st1, st2;
  cin >> st1 >> st2;
  map<char, long long> om1;
  long long res = 0;
  for (long long i = 1; i < st2.size(); i++) om1[st2[i]] = i;
  for (long long i = 1; i < st2.size(); i++)
    res += abs(om1[st2[i]] - om1[st2[i - 1]]);
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) solution();
}
