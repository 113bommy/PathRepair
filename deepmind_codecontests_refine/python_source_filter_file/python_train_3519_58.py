import bisect

N, K = [int(x) for x in input().split()]
V = [int(x) for x in input().split()]
M = min(N, K)

ans = 0
juwel = []
for l in range(M):
    for r in range(M - l):
        juwel = sorted(V[:l] + V[N - r:])
        s = bisect.bisect_left(juwel, 0)
        s = min(s, M - l - r)
        juwel = juwel[s:]
        ans = max(ans, sum(juwel))

print(ans)