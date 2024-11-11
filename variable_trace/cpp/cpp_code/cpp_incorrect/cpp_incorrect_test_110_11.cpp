#include <bits/stdc++.h>
using namespace std;
int gi() {
  int x = 0, c = getchar();
  bool f = 0;
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = 1;
  for (; isdigit(c); c = getchar()) x = x * 10 + (c & 15);
  return f ? -x : x;
}
constexpr int N = (int)1e5 + 5;
int n, x[N], y[N], c[N], _n, _m;
vector<int> _x, _y, hang[3][N], lie[3][N];
bool _check1(int k, int a, int b, int c) {
  int cnt = 0;
  for (int i = 1; i <= _n - 2; ++i) {
    cnt += hang[a][i].size();
    if (cnt >= k) {
      cnt = 0;
      for (int j = i + 1; j < _n; ++j) {
        cnt += hang[b][j].size();
        if (cnt >= k) {
          cnt = 0;
          for (int l = j + 1; l <= _n; ++l) {
            cnt += hang[c][l].size();
          }
          return cnt >= k;
        }
      }
      return 0;
    }
  }
  return 0;
}
bool _check2(int k, int a, int b, int c) {
  int cnt = 0;
  for (int i = 1; i <= _m - 2; ++i) {
    cnt += lie[a][i].size();
    if (cnt >= k) {
      cnt = 0;
      for (int j = i + 1; j < _m; ++j) {
        cnt += lie[b][j].size();
        if (cnt >= k) {
          cnt = 0;
          for (int l = j + 1; l <= _m; ++l) {
            cnt += lie[c][l].size();
          }
          return cnt >= k;
        }
      }
      return 0;
    }
  }
  return 0;
}
bool _check3(int k, int a, int b, int c) {
  int cnt = 0;
  for (int i = 1; i < _n; ++i) {
    cnt += hang[a][i].size();
    if (cnt >= k) {
      cnt = 0;
      for (int j = 1; j < _m; ++j) {
        for (int x : lie[b][j]) {
          if (x >= i + 1) cnt++;
        }
        if (cnt >= k) {
          cnt = 0;
          for (int l = j + 1; l <= _m; ++l) {
            for (int x : lie[c][l]) {
              if (x >= i + 1) cnt++;
            }
          }
          return cnt >= k;
        }
      }
      return 0;
    }
  }
  return 0;
}
bool _check4(int k, int a, int b, int c) {
  int cnt = 0;
  for (int i = 1; i < _m; ++i) {
    cnt += lie[a][i].size();
    if (cnt >= k) {
      cnt = 0;
      for (int j = 1; j < _n; ++j) {
        for (int x : hang[b][j]) {
          if (x >= i + 1) cnt++;
        }
        if (cnt >= k) {
          cnt = 0;
          for (int l = j + 1; l <= _n; ++l) {
            for (int x : hang[c][l]) {
              if (x >= i + 1) cnt++;
            }
          }
          return cnt >= k;
        }
      }
      return 0;
    }
  }
  return 0;
}
bool _check5(int k, int a, int b, int c) {
  int cnt = 0;
  for (int i = _n; i > 1; --i) {
    cnt += hang[a][i].size();
    if (cnt >= k) {
      cnt = 0;
      for (int j = 1; j < _m; ++j) {
        for (int x : lie[b][j]) {
          if (x >= i + 1) cnt++;
        }
        if (cnt >= k) {
          cnt = 0;
          for (int l = j + 1; l <= _m; ++l) {
            for (int x : lie[c][l]) {
              if (x >= i + 1) cnt++;
            }
          }
          return cnt >= k;
        }
      }
      return 0;
    }
  }
  return 0;
}
bool _check6(int k, int a, int b, int c) {
  int cnt = 0;
  for (int i = _m; i > 1; --i) {
    cnt += lie[a][i].size();
    if (cnt >= k) {
      cnt = 0;
      for (int j = 1; j < _n; ++j) {
        for (int x : hang[b][j]) {
          if (x >= i + 1) cnt++;
        }
        if (cnt >= k) {
          cnt = 0;
          for (int l = j + 1; l <= _n; ++l) {
            for (int x : hang[c][l]) {
              if (x >= i + 1) cnt++;
            }
          }
          return cnt >= k;
        }
      }
      return 0;
    }
  }
  return 0;
}
bool _check(int k, int a, int b, int c) {
  return _check1(k, a, b, c) || _check2(k, a, b, c) || _check3(k, a, b, c) ||
         _check4(k, a, b, c) || _check5(k, a, b, c) || _check6(k, a, b, c);
}
bool check(int k) {
  return _check(k, 0, 1, 2) || _check(k, 0, 2, 1) || _check(k, 1, 0, 2) ||
         _check(k, 1, 2, 0) || _check(k, 2, 0, 1) || _check(k, 2, 1, 0);
}
int main() {
  n = gi();
  for (int i = 1; i <= n; ++i) {
    x[i] = gi(), y[i] = gi(), c[i] = gi();
    _x.push_back(x[i]);
    _y.push_back(y[i]);
  }
  sort(_x.begin(), _x.end());
  sort(_y.begin(), _y.end());
  _x.resize(unique(_x.begin(), _x.end()) - _x.begin());
  _y.resize(unique(_y.begin(), _y.end()) - _y.begin());
  _n = _x.size(), _m = _y.size();
  for (int i = 1; i <= n; ++i) {
    x[i] = lower_bound(_x.begin(), _x.end(), x[i]) - _x.begin() + 1;
    y[i] = lower_bound(_y.begin(), _y.end(), y[i]) - _y.begin() + 1;
    hang[c[i] - 1][x[i]].push_back(y[i]);
    lie[c[i] - 1][y[i]].push_back(x[i]);
  }
  int l = 2, r = n / 3;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%d\n", 3 * r);
  return 0;
}
