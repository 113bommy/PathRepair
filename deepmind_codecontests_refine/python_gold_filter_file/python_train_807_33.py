N = int(input())
A = [(a, i) for i, a in enumerate(map(int, input().split()), start=1)]
A.sort(reverse=True)

dp = [[0] * (N + 1) for _ in range(N + 1)]

for s, (a, i) in enumerate(A):
    for l in range(s + 1):
        r = s - l
        dp[l + 1][r] = max(dp[l + 1][r], dp[l][r] + a * (i - (l + 1)))
        dp[l][r + 1] = max(dp[l][r + 1], dp[l][r] + a * (N - r - i))

ans = max([max(d) for d in dp])
print(ans)
