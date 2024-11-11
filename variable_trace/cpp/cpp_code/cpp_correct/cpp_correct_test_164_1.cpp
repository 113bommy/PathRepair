#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 50, LOGN = 17;
const int INF = (int)1e9;
int n, k;
int ord[N], in[N], tim = 0;
char las[N];
int lc[N], rc[N];
int res[N];
string str;
void dfs(int v) {
  if (lc[v] != -1) dfs(lc[v]);
  ord[tim] = v;
  in[v] = tim++;
  if (rc[v] != -1) dfs(rc[v]);
}
void solve(int v, int& rem) {
  int la = -1;
  int cur = v;
  for (int i = 0; i < (rem); ++i) {
    if (cur == -1) break;
    if (las[cur] != ' ' && las[cur] > str[cur]) {
      la = i;
    }
    cur = lc[cur];
  }
  cur = v;
  vector<int> vs;
  for (int i = 0; i < (la + 1); ++i) {
    res[cur] = 1;
    rem--;
    vs.push_back(cur);
    cur = lc[cur];
  }
  while (!vs.empty()) {
    if (rc[vs.back()] != -1) solve(rc[vs.back()], rem);
    vs.pop_back();
  }
}
void print_ans(int v) {
  if (lc[v] != -1) print_ans(lc[v]);
  cout << str[v];
  if (res[v]) cout << str[v];
  if (rc[v] != -1) print_ans(rc[v]);
}
int pos[256];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  cin >> str;
  for (int i = 0; i < (n); ++i) {
    cin >> lc[i] >> rc[i];
    lc[i]--, rc[i]--;
  }
  dfs(0);
  fill(pos, pos + 256, INF);
  for (int i = n - 1; i >= 0; i--) {
    pos[str[ord[i]]] = i;
    char f = ' ';
    for (char c = 'a'; c <= 'z'; c++) {
      if (c != str[ord[i]] && pos[f] > pos[c]) f = c;
    }
    las[ord[i]] = f;
  }
  solve(0, k);
  assert(k >= 0);
  print_ans(0);
}
