from collections import deque

MOD = 10**9 + 7

N = int(input())
G = [[] for i in range(N)]
G0 = [[] for i in range(N)]
for i in range(N-1):
    x, y = map(int, input().split())
    G[x-1].append(y-1)
    G[y-1].append(x-1)

I = []
que = deque([0])
used = [0]*N; used[0] = 1
while que:
    v = que.popleft()
    gv = G0[v]
    I.append(v)
    for w in G[v]:
        if used[w]:
            continue
        gv.append(w)
        used[w] = 1
        que.append(w)
dp = [None for i in range(N)]
for v in reversed(I):
    r0 = r1 = 1
    for w in G0[v]:
        a, b = dp[w]
        r0 = (r0 * (a + b)) % MOD
        r1 = (r1 * a) % MOD
    dp[v] = (r0, r1)
print(sum(dp[0]))