#include <bits/stdc++.h>
using namespace std;
long long aa[310001];
vector<long long> adj[310001];
long long co = 0;
long long st[310001];
long long par[310001][20];
long long endd[310001];
void dfs(long long no, long long par2 = -1) {
  par[no][0] = par2;
  st[no] = co;
  co++;
  for (auto j : adj[no]) {
    dfs(j, no);
  }
  endd[no] = co - 1;
}
long long tree[310001];
void u(long long i, long long j) {
  while (i <= 310000) {
    tree[i] += j;
    i += (i & -i);
  }
}
long long ss(long long i) {
  long long su = 0;
  while (i > 0) {
    su += tree[i];
    i -= (i & -i);
  }
  return su;
}
vector<pair<pair<long long, long long>, long long>> pre[310001];
pair<long long, long long> xx2[310001];
pair<long long, long long> yy[310001];
vector<pair<long long, long long>> xx[310001];
long long ans[310001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, q, k;
  cin >> n >> q >> k;
  for (long long i = 0; i < n; i++) {
    cin >> aa[i];
  }
  for (long long i = 0; i < q; i++) {
    long long l, r;
    cin >> l >> r;
    l--;
    r--;
    pre[l % k].push_back({{l, r}, i});
  }
  vector<pair<long long, long long>> re;
  re.push_back({0, n});
  for (long long i = n - 1; i >= 0; i--) {
    while (re.size()) {
      if (re.back().first >= aa[i]) {
        re.pop_back();
      } else {
        break;
      }
    }
    adj[re.back().second].push_back(i);
    xx2[i] = {i, re.back().second - 1};
    re.push_back({aa[i], i});
  }
  dfs(n);
  for (long long i = 0; i < n; i++) {
    pair<long long, long long> yy = {xx2[i].first % k, xx2[i].second % k};
    long long co = ((xx2[i].second - xx2[i].first + 1)) / k;
    u(st[i] + 1, aa[i] * (co));
    u(endd[i] + 2, -(aa[i] * (co)));
    long long co2 = (xx2[i].second - xx2[i].first) / k;
    co2 += 1;
    if (co2 > co) {
      if (yy.first <= yy.second) {
        xx[yy.first].push_back({i, 1});
        xx[yy.second + 1].push_back({i, -1});
      } else {
        xx[0].push_back({i, 1});
        xx[yy.second + 1].push_back({i, -1});
        xx[yy.first].push_back({i, 1});
      }
    }
  }
  for (long long j = 1; j < 20; j++) {
    for (long long i = 0; i <= n; i++) {
      if (par[i][j - 1] == -1) {
        par[i][j] = -1;
      } else {
        par[i][j] = par[par[i][j - 1]][j - 1];
      }
    }
  }
  for (long long i = 0; i < k; i++) {
    for (auto j : xx[i]) {
      u(st[j.first] + 1, aa[j.first] * j.second);
      u(endd[j.first] + 2, -(aa[j.first] * j.second));
    }
    for (auto j : pre[i]) {
      if (j.first.second - j.first.first + 1 <= k) {
        ans[j.second] = aa[j.first.first];
        continue;
      }
      ans[j.second] = ss(st[j.first.first] + 1);
      long long cur = j.first.first;
      for (long long jj = 19; jj >= 0; jj--) {
        if (par[cur][jj] >= 0) {
          if (par[cur][jj] <= j.first.second) {
            cur = par[cur][jj];
          }
        }
      }
      ans[j.second] -= ss(st[cur] + 1);
      long long xy = cur % k;
      long long cur2 = cur;
      if (xy < i) {
        cur2 += (i - xy);
      } else if (xy > i) {
        cur2 += (k - xy) + i;
      }
      if (cur2 <= j.first.second) {
        ans[j.second] += (((j.first.second - cur2) / k) + 1) * aa[cur];
      }
    }
  }
  for (long long i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
