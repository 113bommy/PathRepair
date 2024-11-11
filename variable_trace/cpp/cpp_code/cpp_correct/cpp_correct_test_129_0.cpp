#include <bits/stdc++.h>
using namespace std;
void fun() {
  long long a, s, d, i, j, k;
  cin >> a;
  vector<long long> vec;
  set<pair<long long, long long> > se;
  set<pair<long long, long long> >::iterator ii;
  se.insert({1000000000000, 1000000000000});
  for (i = 0; i < a; i++) {
    cin >> s;
    se.insert({s, i});
  }
  long long otv = 0;
  for (i = a; i >= 1; i--) {
    ii = se.lower_bound({i, 0});
    long long a1, a2;
    a1 = (*ii).first;
    a2 = (*ii).second;
    if (a1 == i) {
      se.erase(*ii);
    } else {
      ii = se.lower_bound({i * 2 + 1, 0});
      a1 = (*ii).first;
      a2 = (*ii).second;
      if (a1 == 1000000000000) {
        cout << -1 << endl;
        return;
      }
      se.erase(*ii);
      otv++;
    }
  }
  cout << otv << endl;
}
int main() {
  long long a, i;
  cin >> a;
  for (i = 0; i < a; i++) fun();
}
