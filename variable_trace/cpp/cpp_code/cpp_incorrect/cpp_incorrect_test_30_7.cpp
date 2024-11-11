#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e8 + 4;
template <typename T>
inline void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  x *= f;
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = ~x + 1;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
int t, n, ans;
string al;
map<char, bool> book;
void solve(char mo) {
  int sum = 0;
  int l = 0, r = n - 1;
  bool flag = true;
  while (r - l > 1) {
    if (al[r] == al[l])
      l++, r--;
    else if (al[r] != mo && al[l] == mo) {
      l++, sum++;
    } else if (al[r] == mo && al[l] != mo) {
      r--, sum++;
    } else if (al[r] == mo && al[l] == mo) {
      l++, r--, sum++;
    } else {
      flag = true;
      break;
    }
  }
  if (l != r) {
    if (al[l] == mo) {
      l++;
      sum++;
    }
    if (al[r] == mo) {
      r--;
      sum++;
    }
  }
  if (al[r] == al[l] && flag == true) {
    ans = min(ans, sum);
  }
}
int main() {
  read(t);
  while (t--) {
    read(n);
    cin >> al;
    book.clear();
    ans = maxn;
    for (int i = 0; i < n; i++) book[al[i]] = true;
    for (auto i = book.begin(); i != book.end(); i++) {
      solve(i->first);
    }
    if (ans == maxn)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
