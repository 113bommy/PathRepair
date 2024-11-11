from collections import defaultdict, deque
from heapq import heappop, heappush
def inpl(): return list(map(int, input().split()))

N, M = inpl()
S, T = inpl()
G = [[] for _ in range(N+1)]
MOD = 10**9 + 7
for _ in range(M):
    u, v, d = inpl()
    G[u].append((v, d))
    G[v].append((u, d))

cost = [10**18]*(N+1)
appear = [0]*(N+1)

Q = [(0, S)]
cost[S] = 0
appear[S] = 1

while Q:
    c, p = heappop(Q)
    if cost[p] < c:
        continue
    for q, d in G[p]:
        if cost[p] + d == cost[q]:
            appear[q] = (appear[q] + appear[p])%MOD
        elif cost[p] + d < cost[q]:
            cost[q] = cost[p] + d
            appear[q] = appear[p] % MOD
            heappush(Q, (cost[q], q))

end = cost[T]*1
ans = pow(appear[T], 2, MOD)

Q = [(0, T)]
cost2 = [10**18]*(N+1)
cost2[T] = 0
appear2 = [0]*(N+1)
appear2[T] = 1
while Q:
    c, p = heappop(Q)
    if cost2[p] < c:
        continue
    for q, d in G[p]:
        if cost[p] - d != cost[q]:
            continue
        if cost2[p] + d == cost2[q]:
            appear2[q] = (appear2[q] + appear2[p])%MOD
        elif cost2[p] + d < cost2[q]:
            cost2[q] = cost2[p] + d
            appear2[q] = appear2[p] % MOD
            heappush(Q, (cost[q], q))

Q = deque([S])
searched = [False]*(N+1)
searched[S] = True

while Q:
    p = Q.pop()
    if 2*cost2[p] == end:
        ans = (ans - (appear[p]*appear2[p])**2)%MOD

    for q, d in G[p]:
        if cost2[p] - d != cost2[q]:
            continue
        if 2*cost2[q] < end < 2*cost2[p]:
            ans = (ans - (appear[p]*appear2[q])**2)%MOD
        if not searched[q]:
            Q.append(q)
            searched[q] = True
print(ans)