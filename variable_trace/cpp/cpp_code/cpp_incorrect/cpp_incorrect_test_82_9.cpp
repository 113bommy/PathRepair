#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int arr[300009], b[300009];
vector<pair<int, int> > adj[300009], query[300009];
const int N = 500;
long long ans[300009], par[300009];
int main() {
  int n, q, k;
  scanf("%d%d%d", &n, &q, &k);
  deque<pair<int, int> > deq;
  for (int i = 1; i <= n; i++) {
    scanf("%d", arr + i);
    while (!deq.empty() and deq.back().first >= arr[i]) deq.pop_back();
    while (!deq.empty() and i - deq.front().second > k) deq.pop_front();
    deq.push_back(make_pair(arr[i], i));
    b[i] = deq.front().first;
  }
  for (int i = 1; i <= n; i++) adj[i % k].push_back(make_pair(i, b[i]));
  if (k > N) {
    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);
      int mn = 1000000007;
      long long res = arr[l];
      int pos = upper_bound(adj[l % k].begin(), adj[l % k].end(),
                            make_pair(l, 1000000007)) -
                adj[l % k].begin();
      while (pos < (int)adj[l % k].size() and adj[l % k][pos].first <= r)
        umin(mn, adj[l % k][pos++].second), res += mn;
      printf("%lld\n", res);
    }
    return 0;
  }
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    query[l].push_back(make_pair(r, i));
    ans[i] = arr[l];
  }
  for (int i = 0; i < k; i++) {
    memset(par, 0, sizeof par);
    int sz = adj[i].size();
    vector<pair<int, int> > v;
    for (int j = sz - 1; j >= 0; j--) {
      int l = adj[i][j].first, val = adj[i][j].second;
      if (!v.empty()) {
        for (int h = 0; h < int(query[l].size()); h++) {
          int r = query[l][h].first;
          int idx = query[l][h].second;
          int R = upper_bound(adj[i].begin(), adj[i].end(),
                              make_pair(r, 1000000007)) -
                  adj[i].begin();
          int st = 0, en = v.size() - 1;
          while (st + 1 < en) {
            int mid = (st + en) >> 1;
            if (v[mid].second < R)
              en = mid;
            else
              st = mid;
          }
          if (v[st].second < R) en = st;
          int who = v[en].second;
          int me = v[en].first;
          if (who < R)
            ans[idx] += par[v[0].second] - par[who] + (R - who) * 1LL * me;
        }
      }
      while (!v.empty() and v.back().first >= val) v.pop_back();
      if (!v.empty()) {
        int next_ind = v.back().second;
        par[j] = par[next_ind] + (next_ind - j) * 1LL * val;
      }
      v.push_back(make_pair(val, j));
    }
  }
  for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
  return 0;
}
