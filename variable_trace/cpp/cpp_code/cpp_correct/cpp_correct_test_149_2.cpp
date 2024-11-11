#include <bits/stdc++.h>
using namespace std;
string s;
int n, k, t, cnt[2001];
unsigned long long x;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k >> x;
    cin >> s;
    string news = "";
    int len = -1;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        news += s[i];
        if (s[i] == '*') {
          len++;
          cnt[len] = k;
        } else {
          len++;
          cnt[len] = 0;
        }
      } else {
        if (s[i] == s[i - 1] && s[i] == '*') {
          cnt[len] += k;
        } else {
          news += s[i];
          if (s[i] == '*') {
            len++;
            cnt[len] = k;
          } else {
            len++;
            cnt[len] = 0;
          }
        }
      }
    }
    len = news.size();
    unsigned long long tt = 1, vt = 0;
    vector<unsigned long long> thutu;
    thutu.push_back(1);
    for (int i = len - 1; i >= 0; i--) {
      unsigned long long prett = tt;
      if (cnt[i] > 0) {
        tt = tt * (cnt[i] + 1);
        thutu.push_back(tt);
        if (x / prett <= cnt[i]) {
          vt = i;
          break;
        }
      }
    }
    for (int i = 0; i < vt; i++) {
      if (news[i] == 'a') {
        cout << news[i];
      }
    }
    if (thutu.size()) {
      thutu.pop_back();
    }
    for (int i = vt; i < len; i++) {
      if (news[i] == 'a') {
        cout << news[i];
      } else {
        if (thutu.size()) {
          unsigned long long giasu = thutu.back();
          thutu.pop_back();
          unsigned long long o = x / giasu;
          if (x % giasu == 0) {
            o--;
          }
          x -= o * giasu;
          for (int j = 1; j <= o; j++) {
            cout << 'b';
          }
        }
      }
    }
    cout << "\n";
  }
}
