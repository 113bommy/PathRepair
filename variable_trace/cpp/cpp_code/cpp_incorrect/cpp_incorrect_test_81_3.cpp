#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
template <typename T>
inline T read() {
  T x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) x = (x * 10) + (ch ^ 48), ch = getchar();
  return !f ? x : -x;
}
const int N = 500010;
int n, d, ans;
pii p[N];
int main() {
  n = read<int>(), d = read<int>();
  for (int i = 1; i <= n; i++)
    p[i].first = read<int>(), p[i].second = read<int>();
  sort(p + 1, p + n + 1, [&](pii a, pii b) {
    return max(a.first, a.second) != max(b.first, b.second)
               ? max(a.first, a.second) < max(b.first, b.second)
               : a.first < b.first;
  });
  for (int i = 1; i <= n; i++)
    if (p[i].first >= d) d = p[i].second, ans++;
  cout << ans << endl;
  return 0;
}
