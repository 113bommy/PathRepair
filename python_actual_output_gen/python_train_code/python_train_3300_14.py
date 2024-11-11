N, K = map(int, input().split())
xy = [list(map(int, input().split())) for i in range(N)]
ans = 10**20
xy.sort()
for l in range(N-K+1):
    for r in range(l+K, N+1):
        y = sorted(xy, key = lambda v: v[1])
        for i in range(r-l-K+1):
            sq = (xy[r-1][0] - xy[l][0]) * (y[i+K-1][1] - y[i][1])
            ans = min(ans, sq)
print(ans)