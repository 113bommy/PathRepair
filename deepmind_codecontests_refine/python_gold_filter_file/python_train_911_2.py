N, *P = map(int, open(0).read().split())

dp = [0] + [min(i, j, N - 1 - i, N - 1 - j) for i in range(N) for j in range(N)]
memo = [1] * (N * N + 1)

def move(fr, to):
    if dp[to] > dp[fr] + memo[fr]:
        dp[to] = dp[fr] + memo[fr]
        S.append(to)

ans = 0
for p in P:
    ans += dp[p]
    memo[p] = 0

    S = [p]
    while S:
        v = S.pop()

        q, r = divmod(v - 1, N)
        if r != 0:
            move(v, v - 1)
        if r != N - 1:
            move(v, v + 1)
        if q < N - 1:
            move(v, v + N)
        if q >= 1:
            move(v, v - N)

print(ans)