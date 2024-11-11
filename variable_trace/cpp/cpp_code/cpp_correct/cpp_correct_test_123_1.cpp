#include <bits/stdc++.h>
using namespace std;
constexpr long long INF = 1e14;
int n, k;
vector<int> L[200005];
int uz[200005];
int tata[200005];
vector<pair<int, int>> frunze;
void DFS(int x, int d = 0) {
  uz[x] = 1;
  for (int i : L[x])
    if (!uz[i]) {
      tata[i] = x;
      DFS(i, d + 1);
    }
  if (L[x].size() == 1 && x != 1) frunze.push_back({d, x});
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    L[x].push_back(y);
    L[y].push_back(x);
  }
  DFS(1);
  if (k >= frunze.size()) {
    long long maxim = 0;
    for (int i = frunze.size(); i <= k; i++)
      maxim = max(maxim, 1ll * (n - i) * i);
    cout << maxim << '\n';
  } else {
    sort(frunze.begin(), frunze.end(), greater<pair<int, int>>());
    vector<int> moves;
    for (auto fr : frunze) {
      int scor = 0;
      int aux = fr.second;
      while (aux && uz[aux]) {
        uz[aux] = 0;
        scor++;
        aux = tata[aux];
      }
      moves.push_back(scor);
    }
    sort(moves.begin(), moves.end(), greater<int>());
    int nr = 0;
    for (int i = 0; i < k; i++) nr += moves[i];
    long long minim = INF;
    for (int i = 0; i <= n - nr; i++)
      minim = min(minim, 1ll * (n - k - i) * (k - i));
    cout << minim << '\n';
  }
  return 0;
}
