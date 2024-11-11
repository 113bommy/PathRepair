import sys
from heapq import heappush, heappop


I = sys.stdin.readlines()
N, Q = map(int, I[0].split())
P = []
for i in range(1, N + 1):
    s, t, x = map(int, I[i].split())
    P.append((s - x, t - 1 - x, x))
P.sort()


q = []
cur = 0
ans = [-1] * Q
for i in range(N + 1, N + Q + 1):
    d = int(I[i])
    while cur < N and P[cur][0] <= d:
        s, t, x = P[cur]
        heappush(q, (x, t))
        cur += 1
    while q and q[0][1] < d:
        heappop(q)
    if q:
        ans[i - N - 1] = q[0][0]

print(*ans, sep='\n')
