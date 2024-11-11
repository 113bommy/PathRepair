#include <bits/stdc++.h>
using namespace std;
long long fp(long long x, long long y, long long m = 998244353) {
  long long ANS = 1;
  while (y) {
    if (y & 1) ANS = (ANS * x) % 998244353;
    x = (x * x) % 998244353;
    y >>= 1;
  }
  return ANS;
}
long long inv(long long x, long long m = 998244353) { return fp(x, m - 2); }
long long testcases, x, y, z, n, TQ, X[200001], Y[200001], Z[200001], CNT;
vector<pair<pair<long long, long long>, pair<long long, long long>>> lolz;
void SETR(long long idx, long long DIFF) {
  long long DIFF2 = X[idx] - Y[idx];
  long long ZZZ = DIFF - DIFF2, ZZ = Z[idx] - abs(ZZZ);
  if (ZZZ < 0) {
    X[idx] = -ZZZ;
    Y[idx] = 0;
  } else {
    Y[idx] = ZZZ;
    X[idx] = 0;
  }
  X[idx] += ZZ / 2;
  Y[idx] += ZZ / 2;
}
void ASSIGN(long long L, long long R) {
  vector<pair<pair<long long, long long>, long long>> F;
  for (long long i = L; i <= R; i++) {
    F.push_back(
        {{lolz[i].second.first, lolz[i].second.second}, lolz[i].first.second});
  }
  sort(F.begin(), F.end());
  long long MM = INT_MAX;
  CNT++;
  long long LST = 0;
  for (long long i = 0; i < F.size(); i++) {
    if (MM < F[i].first.first) {
      for (long long l = LST; l < i; l++) {
        SETR(F[l].second, MM);
      }
      CNT++, MM = INT_MAX;
      LST = i;
    }
    MM = min(MM, F[i].first.second);
  }
  for (long long l = LST; l < F.size(); l++) {
    SETR(F[l].second, MM);
  }
}
int32_t main() {
  iostream::sync_with_stdio(0), cin.tie(0);
  cin >> testcases;
  while (testcases--) {
    cin >> n;
    lolz.clear();
    CNT = 0;
    for (long long i = 0; i < n; i++) {
      cin >> x >> y >> z;
      X[i] = x, Y[i] = y, Z[i] = z;
      long long LB, UB, QQ = min(z, x), TOTz = x + y - z;
      x -= QQ, y -= z - QQ;
      LB = x - y;
      x += QQ, y += z - QQ;
      QQ = min(z, y);
      x -= z - QQ, y -= QQ;
      UB = x - y;
      lolz.push_back({{TOTz, i}, {min(LB, UB), max(UB, LB)}});
    }
    sort(lolz.begin(), lolz.end());
    long long LAST = lolz[0].first.first, ID = 0;
    for (long long i = 1; i < lolz.size(); i++) {
      if (LAST != lolz[i].first.first)
        ASSIGN(ID, i - 1), ID = i, LAST = lolz[i].first.first;
    }
    ASSIGN(ID, lolz.size() - 1);
    cout << CNT << '\n';
    for (long long i = 0; i < n; i++) cout << X[i] << ' ' << Y[i] << '\n';
  }
}
