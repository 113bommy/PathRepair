#include <bits/stdc++.h>
using namespace std;
priority_queue<long long, std::vector<long long>, std::greater<long long> > pqs;
queue<long long> q;
stack<long long> sta;
set<long long> st;
set<long long>::iterator P;
long long i, j, n, m, t, k, a, b, c, x, mx, mn;
string s, s1;
char z;
vector<long long> v;
map<string, long long> mp, pm;
string DecToBin(long long n) {
  string res = "";
  while (n) res += (char)((n % 2) + 48), n /= 2;
  reverse(res.begin(), res.end());
  return res;
}
void dp(string ss, string s) {
  if (ss == s) {
    k = 1;
    return;
  }
  if (mp[ss] || ss.size() > 70) return;
  mp[ss] = 1;
  string ss1;
  ss1 = ss;
  ss1 += '0';
  reverse(ss1.begin(), ss1.end());
  long long j = 0;
  while (ss1[j] == '0') j++;
  ss1 = ss1.substr(j, ss1.size() - j);
  dp(ss1, s);
  ss1 = ss;
  ss1 += '1';
  reverse(ss1.begin(), ss1.end());
  dp(ss1, s);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int T = 1;
  while (T--) {
    i = j = n = m = t = k = a = b = c = x = mx = mn = 0;
    cin >> a >> b;
    s1 = DecToBin(a);
    s = DecToBin(b);
    dp(s1, s);
    if (k)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
