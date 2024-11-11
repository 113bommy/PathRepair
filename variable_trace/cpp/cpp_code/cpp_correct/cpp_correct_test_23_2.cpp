#include <bits/stdc++.h>
int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int N, M;
  std::cin >> N >> M;
  std::vector<int> A(N + 1, 0);
  for (int i = 1; i <= N; ++i) std::cin >> A[i];
  std::vector<int> Sta(N + 1, 0), Ls(N + 1, 0), Rs(N + 1, 0);
  int top = 0, mn = A[1];
  for (int i = 1; i <= N; ++i) {
    while (top && A[Sta[top]] > A[i]) Ls[i] = Sta[top--];
    if (top) Rs[Sta[top]] = i;
    Sta[++top] = i, mn = std::min(mn, A[i]);
  }
  int rt = 0;
  for (int i = 1; i <= N; ++i)
    if (mn == A[i]) rt = i;
  std::vector<std::vector<long long>> dp(N + 1,
                                         std::vector<long long>(M + 1, -1E17));
  std::vector<int> Sz(N + 1, 0);
  auto Merge = [&](int u, int v) {
    if (!v) return;
    std::vector<long long> f(M + 1, -1E18);
    for (int a = 0; a <= Sz[u]; ++a)
      for (int b = 0; b <= Sz[v] && a + b <= M; ++b)
        f[a + b] = std::max(f[a + b], dp[u][a] + dp[v][b] - 2ll * a * b * A[u]);
    dp[u] = f, Sz[u] += Sz[v];
  };
  std::function<void(int)> solve = [&](int u) {
    if (!u) return;
    dp[u][0] = 0, dp[u][1] = 1ll * A[u] * (M - 1), Sz[u] = 1;
    solve(Ls[u]), solve(Rs[u]);
    Merge(u, Ls[u]), Merge(u, Rs[u]);
  };
  solve(rt);
  long long ans = -2E18;
  for (int i = 1; i <= N; ++i) ans = std::max(ans, dp[i][M]);
  std::cout << ans << '\n';
  return 0;
}
