#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
long long a[maxn], n;
char b[maxn];
long long st[maxn], top, ans, L[maxn];
int vis[maxn], x, p[maxn], minn[maxn];
vector<int> v[maxn];
void oula() {
  for (int i = 2; i < maxn; i++) {
    if (vis[i] == 0) p[++x] = i, minn[i] = i;
    for (int j = 1; j <= x && i * p[j] < maxn; j++) {
      vis[i * p[j]] = 1;
      minn[i * p[j]] = p[j];
      if (i % p[j] == 0) break;
    }
  }
}
int main() {
  oula();
  scanf("%lld", &n);
  for (int i = (1); i <= (n); ++i) scanf("%lld", &a[i]);
  scanf("%s", b + 1);
  for (int i = 1; i <= n; i++) {
    long long temp = a[i];
    if (b[i] == '*') {
      L[i] = i;
      while (temp > 1) {
        long long t = minn[temp];
        v[t].push_back(i);
        temp /= t;
      }
      if (temp > 1) v[temp].push_back(i);
    } else {
      int flag = 1, mi = 1e9;
      while (temp > 1) {
        long long t = minn[temp];
        if (v[t].size())
          mi = min(mi, v[t].back()), v[t].pop_back();
        else {
          flag = 0;
        }
        temp /= t;
      }
      if (temp > 1 && v[temp].size())
        mi = min(mi, v[temp].back()), v[temp].pop_back();
      else if (temp > 1 && v[temp].size() == 0)
        flag = 0;
      if (!flag)
        L[i] = -1;
      else
        L[i] = mi;
    }
  }
  st[0] = n + 1;
  top = 0;
  for (int i = n; i >= 1; i--) {
    while (top && L[i] <= L[st[top]]) top--;
    if (i == L[i]) ans += (st[top] - i);
    st[++top] = i;
  }
  printf("%lld", ans);
  return 0;
}
