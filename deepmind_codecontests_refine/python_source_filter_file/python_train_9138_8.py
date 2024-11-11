from collections import deque

n = int(input())
s = [input() for _ in range(n)]

# 二部グラフ判定
memo = [-1] * n
memo[0] = 0
q = deque((0, -1))
while q:
    v, p = q.popleft()
    for nv in range(n):
        if s[v][nv] == '1':
            if nv == p:
                continue
            if memo[nv] == -1:
                memo[nv] = (memo[v] + 1) % 2
                q.append((nv, v))
            else:
                if memo[nv] == memo[v]:
                    print(-1)
                    exit()

# ワーシャルフロイドでグラフの直径を求めてもよし
INF = float('inf')
dp = [[1 if c == '1' else INF for c in row] for row in s]

for i in range(n):
    dp[i][i] = 0

for k in range(n):
    for i in range(n):
        for j in range(n):
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])

dist = 0
for i in range(n):
    d = 0
    for j in range(n):
        d = max(d, dp[i][j])
    dist = max(d, dist)

print(dist+1)