#include <bits/stdc++.h>
using namespace std;
template <class T>
int chkmax(T& a, T b) {
  if (b > a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
int chkmin(T& a, T b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class iterator>
void output(iterator begin, iterator end, ostream& out = cerr) {
  while (begin != end) {
    out << (*begin) << " ";
    begin++;
  }
  out << endl;
}
template <class T>
void output(T x, ostream& out = cerr) {
  output(x.begin(), x.end(), out);
}
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
struct pt {
  long long x, y;
  pt() : x(0), y(0) {}
  pt(long long _x, long long _y) : x(_x), y(_y) {}
};
pt operator+(pt a, pt b) { return pt(a.x + b.x, a.y + b.y); }
pt operator-(pt a, pt b) { return pt(a.x - b.x, a.y - b.y); }
long long operator*(pt a, pt b) { return a.x * b.x + a.y * b.y; }
long long operator/(pt a, pt b) { return a.x * b.y - a.y * b.x; }
long double dist(pt a, pt b) { return sqrtl((long double)((b - a) * (b - a))); }
istream& operator>>(istream& is, pt& p) {
  is >> p.x >> p.y;
  return is;
}
ostream& operator<<(ostream& os, const pt& p) {
  os << p.x << " " << p.y;
  return os;
}
int half_plane(pt a) { return (a.y > 0 || (a.y == 0 && a.x > 0)) ^ 1; }
bool polar_cmp(pt a, pt b) {
  int ha = half_plane(a), hb = half_plane(b);
  if (ha < hb) {
    return 1;
  }
  if (ha > hb) {
    return 0;
  }
  return (a / b > 0);
}
bool operator==(const pt& a, const pt& b) { return a.x == b.x && a.y == b.y; }
bool operator<(const pt& a, const pt& b) {
  return tie(a.x, a.y) < tie(b.x, b.y);
}
const long double INF = 1e18;
int n, k, ls;
bool have_other;
pt other;
vector<pt> a, line;
pt norm(pt x) { return half_plane(x) ? pt() - x : x; }
bool try_to_find_line(int id) {
  auto cmp = [](pt a, pt b) { return polar_cmp(a, b); };
  map<pt, int, decltype(cmp)> dircnt(cmp);
  int eq = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == a[id]) {
      eq++;
    } else {
      dircnt[norm(a[i] - a[id])]++;
    }
  }
  for (auto [dir, cnt] : dircnt) {
    if (cnt >= n - eq - 1) {
      for (int i = 0; i < n; ++i) {
        if ((a[i] - a[id]) / dir == 0 && (have_other || i < n - 1)) {
          line.push_back(a[i]);
        } else {
          other = a[i];
          have_other = true;
        }
      }
      sort(line.begin(), line.end());
      return true;
    }
  }
  return false;
}
void solve_other() {
  long double ans = INF;
  for (int i = 0; i < ls; ++i) {
    chkmin(ans, dist(other, line[i]) + dist(line[i], line[0]) +
                    dist(line[0], line[ls - 1]));
    chkmin(ans, dist(other, line[i]) + dist(line[i], line[ls - 1]) +
                    dist(line[0], line[ls - 1]));
  }
  cout << ans << '\n';
  exit(0);
}
void solve_id(int id) {
  long double ans = INF;
  for (int i = 0; i < ls; ++i) {
    chkmin(ans, dist(line[0], line[ls - 1]) * 2.0 - dist(line[id], line[i]) +
                    dist(line[i], other));
  }
  for (int i = 0; i <= id - 1; ++i) {
    chkmin(ans, dist(line[id], line[ls - 1]) + dist(line[ls - 1], line[i + 1]) +
                    dist(line[i + 1], other) + dist(other, line[i]) +
                    dist(line[i], line[0]));
  }
  for (int i = id; i < ls - 1; ++i) {
    chkmin(ans, dist(line[id], line[0]) + dist(line[0], line[i]) +
                    dist(line[i], other) + dist(other, line[i + 1]) +
                    dist(line[i + 1], line[ls - 1]));
  }
  for (int i = 1; i <= id; ++i) {
    chkmin(ans, dist(line[id], line[ls - 1]) * 2.0 + dist(line[id], line[i]) +
                    dist(line[i], other) + dist(other, line[0]) +
                    dist(line[0], line[i - 1]));
  }
  for (int i = id; i < ls - 1; ++i) {
    chkmin(ans, dist(line[id], line[0]) * 2.0 + dist(line[id], line[i]) +
                    dist(line[i], other) + dist(other, line[ls - 1]) +
                    dist(line[ls - 1], line[i + 1]));
  }
  if (id != 0 && id != ls - 1) {
    chkmin(ans, dist(line[id], line[0]) + dist(line[0], other) +
                    dist(other, line[id + 1]) +
                    dist(line[id + 1], line[ls - 1]));
    chkmin(ans, dist(line[id], line[0]) + dist(line[0], other) +
                    dist(other, line[ls - 1]) +
                    dist(line[ls - 1], line[id + 1]));
    chkmin(ans, dist(line[id], line[ls - 1]) + dist(line[ls - 1], other) +
                    dist(other, line[id - 1]) + dist(line[id - 1], line[0]));
    chkmin(ans, dist(line[id], line[ls - 1]) + dist(line[ls - 1], other) +
                    dist(other, line[0]) + dist(line[0], line[id - 1]));
  }
  cout << ans << '\n';
  exit(0);
}
signed main() {
  cout << setprecision(10) << fixed;
  fast_io();
  cin >> n >> k;
  k--;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (!try_to_find_line(0)) {
    assert(try_to_find_line(1));
  }
  assert(line.size() == n - 1);
  ls = line.size();
  if (a[k] == other) {
    solve_other();
  }
  for (int i = 0; i < line.size(); ++i) {
    if (line[i] == a[k]) {
      solve_id(i);
    }
  }
  assert(false);
}
