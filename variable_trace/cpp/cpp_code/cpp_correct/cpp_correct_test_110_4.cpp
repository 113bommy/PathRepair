#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const long long N = 2e18;
struct ppp {
  long long x, y;
};
long long c[4], n;
vector<ppp> h[5], s[5];
long long get(long long lx, long long rx, long long ly, long long ry,
              long long k) {
  long long l = N, r = -N, num = 0;
  for (auto i : h[c[2]]) {
    if (i.x >= lx && i.x <= rx && i.y >= ly && i.y <= ry) {
      num++;
      if (num == k) {
        l = i.x;
        break;
      }
    }
  }
  num = 0;
  for (auto i : h[c[3]]) {
    if (i.x > l && i.x <= rx && i.y >= ly && i.y <= ry) {
      num++;
      if (num == k) {
        r = i.x;
        break;
      }
    }
  }
  if (r > l) return 1;
  l = N, r = -N, num = 0;
  for (auto i : s[c[2]]) {
    if (i.x >= lx && i.x <= rx && i.y >= ly && i.y <= ry) {
      num++;
      if (num == k) {
        l = i.y;
        break;
      }
    }
  }
  num = 0;
  for (auto i : s[c[3]]) {
    if (i.x >= lx && i.x <= rx && i.y > l && i.y <= ry) {
      num++;
      if (num == k) {
        r = i.y;
        break;
      }
    }
  }
  if (r > l) return 1;
  return 0;
}
long long check(long long x) {
  c[1] = 1;
  c[2] = 2;
  c[3] = 3;
  do {
    long long l = h[c[1]][x - 1].x;
    if (get(l + 1, N, -N, N, x)) return 1;
    long long r = h[c[1]][n / 3 - x].x;
    if (get(-N, r - 1, -N, N, x)) return 1;
    l = s[c[1]][x - 1].y;
    if (get(-N, N, l + 1, N, x)) return 1;
    r = s[c[1]][n / 3 - x].y;
    if (get(-N, N, -N, r - 1, x)) return 1;
  } while (next_permutation(c + 1, c + 4));
  return 0;
}
bool cmp1(ppp i, ppp j) { return i.x < j.x; }
bool cmp2(ppp i, ppp j) { return i.y < j.y; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long x, y, w;
    cin >> x >> y >> w;
    h[w].push_back({x, y});
    s[w].push_back({x, y});
  }
  for (long long i = 1; i <= 3; i++) {
    sort(h[i].begin(), h[i].end(), cmp1);
    sort(s[i].begin(), s[i].end(), cmp2);
  }
  long long l = 1, r = n / 3;
  while (r >= l) {
    long long mid = (l + r) / 2;
    if (check(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  cout << r * 3 << endl;
}
