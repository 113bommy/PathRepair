#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool com(pair<int, int> a, pair<int, int> b) {
  return abs(a.first - a.second) < abs(b.first - b.second);
}
void solved() {
  int n, x, y;
  cin >> n;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back({x, y});
  }
  sort(v.begin(), v.end(), com);
  int ar[n + 1];
  memset(ar, 0, sizeof(ar));
  for (auto it : v) {
    int a = it.first, b = it.second;
    if (ar[a] == 0) {
      cout << a << ' ' << b << ' ' << a << endl;
      ar[a] = 1;
    } else if (ar[b] == 0) {
      cout << a << ' ' << b << ' ' << b << endl;
      ar[b] = 1;
    } else {
      for (int i = a; i <= b; i++) {
        if (ar[i] == 0) {
          cout << a << ' ' << b << ' ' << i << endl;
          ar[i] = 1;
          break;
        }
      }
    }
  }
}
int main() {
  long long int tc;
  cin >> tc;
  while (tc--) {
    solved();
  }
}
