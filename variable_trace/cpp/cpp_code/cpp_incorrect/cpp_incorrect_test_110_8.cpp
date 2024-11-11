#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5 + 5;
struct Point {
  int x, y, c, idx;
  Point() { x = y = c = idx = 0; }
  void rotate() {
    swap(x, y);
    x = -x;
  }
} P[MAXN], Q[MAXN];
bool operator<(Point a, Point b) {
  return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}
bool byY(Point a, Point b) { return make_pair(a.y, a.x) < make_pair(b.y, b.x); }
int perm[3];
int n;
bool check(int k) {
  iota(perm, perm + 3, 1);
  do {
    int p = 0, cnt = 0;
    while (p < n && (cnt < k || P[p].x == P[p + 1].x)) {
      p++;
      cnt += (P[p].c == perm[0]);
    }
    int q = p;
    cnt = 0;
    while (q < n && (cnt < k || P[q].x == P[q + 1].x)) {
      q++;
      cnt += (P[q].c == perm[1]);
    }
    cnt = 0;
    for (int i = q + 1; i <= n; i++) {
      cnt += (P[i].c == perm[2]);
    }
    if (cnt >= k) {
      return 1;
    }
    vector<Point> T;
    for (int i = 1; i <= n; i++) {
      if (Q[i].idx > p) {
        T.push_back(Q[i]);
      }
    }
    q = 0;
    cnt = 0;
    while (q + 1 < (int)(T).size() && (cnt < k || T[q].y == T[q + 1].y)) {
      q++;
      cnt += (T[q].c == perm[1]);
    }
    cnt = 0;
    for (int i = q + 1; i < (int)(T).size(); i++) {
      cnt += (T[i].c == perm[2]);
    }
    if (cnt >= k) {
      return 1;
    }
  } while (next_permutation(perm, perm + 3));
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> P[i].x >> P[i].y >> P[i].c;
  }
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    perm[i] = i;
  }
  for (int rot = 0; rot < 4; rot++) {
    sort(P + 1, P + n + 1);
    for (int i = 1; i <= n; i++) {
      P[i].idx = i;
      Q[i] = P[i];
    }
    sort(Q + 1, Q + n + 1, byY);
    int l = 1, r = n / 3, opt = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid)) {
        opt = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    ans = max(ans, opt);
    for (int i = 1; i <= n; i++) {
      P[i].rotate();
    }
  }
  cout << ans * 3 << endl;
  return 0;
}
