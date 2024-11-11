from sys import stdin

N, S = map(int, stdin.readline().split())
A = list(map(int,stdin.readline().split()))
M = 998244353
V = max(max(A), S)

ans = 0
cs = [0 for _ in range(V + 1)]
for i, a in enumerate(A):
    dp = [0 for _ in range(V + 1)]
    dp[a] = i + 1
    for s in range(a + 1, S + 1):
        dp[s] = cs[s - a]
    cs = [(a + b) % M for a, b in zip(cs, dp)]
    ans = (ans + (N - i) * dp[S]) % M
print(ans)