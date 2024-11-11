N, M = map(int, input().split())
edges = [[] for _ in range(N)]

for _ in range(M):
    s, t = map(int, input().split())
    s -= 1
    t -= 1
    edges[s].append(t)

def E(stop):
    dp = [-1] * N
    dp[N - 1] = 0
    for i in range(N - 1)[:: -1]:
        total = 0
        mxI = 0
        for to in edges[i]:
            total += dp[to]
            if mxI < dp[to]:
                mxI = dp[to]
        size = len(edges[i])
        if size > 1 and stop == i:
            size -= 1
            total -= mxI
        dp[i] = total / size + 1
    return dp[0]

ans = float('inf')
for s in range(N):
    ans = min(ans, E(s))

print(ans)
