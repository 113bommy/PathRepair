# d
N,K = map(int, input().split())
xy = []
for _ in range(N):
    xy.append( tuple(map(int, input().split())) )
xs,ys = map(list, zip(*xy))
xs.sort()
ys.sort()
ans = float('inf')
for l in range(N):
    for r in range(l+1,N):
        for b in range(N):
            for t in range(b+1,N):
                xl,xr = xs[l],xs[r]
                yb,yt = ys[b],ys[t]
                cnt = 0
                for xi,yi in xy:
                    if xl<=xi<=xr and yb<=yi<=yt: 
                        cnt += 1
                if cnt>=K:
                    ans = min(ans, (xr-xl)*(yt-yb))
print(ans)