#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int INF = INT_MAX;
const long long LLINF = 1000000000000000000LL;
const long long MAX = 200005;
const long long MOD = 998244353;
struct DSU {
  int N;
  int parent[MAX], member[MAX];
  DSU(int n) {
    N = n;
    for (int i = 0; i < N; i++) {
      parent[i] = -1;
      member[i] = 1;
    }
  }
  int findRoot(int n) {
    if (parent[n] == -1) {
      return n;
    }
    return parent[n] = findRoot(parent[n]);
  }
  void makeUnion(int r1, int r2) {
    r1 = findRoot(r1);
    r2 = findRoot(r2);
    if (r1 == r2) {
      return;
    }
    if (member[r1] < member[r2]) {
      swap(r1, r2);
    }
    parent[r2] = r1;
    member[r1] += member[r2];
  }
};
struct mine {
  long long x, y, n;
  mine() { x = y = n = 0; }
  mine(long long _x, long long _y, long long _n) : x(_x), y(_y), n(_n){};
};
bool cmpx(mine& left, mine& right) {
  if (left.x == right.x) {
    return left.y < right.y;
  }
  return left.x < right.x;
}
bool cmpy(mine& left, mine& right) {
  if (left.y == right.y) {
    return left.x < right.x;
  }
  return left.y < right.y;
}
void solve() {
  long long N, K;
  cin >> N >> K;
  vector<mine> A(N);
  vector<long long> T(N);
  DSU U(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].x >> A[i].y >> T[i];
    A[i].n = i;
  }
  sort(A.begin(), A.end(), cmpx);
  for (int i = 0; i < N - 1; i++) {
    if (A[i].x == A[i + 1].x && A[i + 1].y - A[i].y <= K) {
      U.makeUnion(A[i].n, A[i + 1].n);
    }
  }
  sort(A.begin(), A.end(), cmpy);
  for (int i = 0; i < N - 1; i++) {
    if (A[i].y == A[i + 1].y && A[i + 1].x - A[i].x <= K) {
      U.makeUnion(A[i].n, A[i + 1].n);
    }
  }
  vector<long long> idx(N), C(N);
  long long m = 0;
  for (int i = 0; i < N; i++) {
    C[i] = LLINF;
    if (U.parent[i] == -1) {
      idx[m] = i;
      ++m;
    }
  }
  for (int i = 0; i < N; i++) {
    long long r = U.findRoot(i);
    C[idx[r]] = min(C[idx[r]], T[i]);
  }
  sort(C.begin(), C.begin() + m);
  reverse(C.begin(), C.begin() + m);
  long long ans = 0;
  for (long long i = 0; i < m; i++) {
    ans = max(ans, min(C[i], i));
  }
  cout << ans << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
