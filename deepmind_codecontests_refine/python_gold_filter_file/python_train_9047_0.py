while True:
    N,W = map(int,input().split())
    if N == 0: break
    src = [int(input()) for i in range(N)]
    highest = max(src)
    bands = highest//W + 1
    hist = [0 for i in range(bands)]
    for i in range(N):
        hist[src[i] // W] += 1
    ans = maxn = 0
    for i,n in enumerate(hist):
        ans += n * (bands-1-i)
        maxn = max(n, maxn)
    print(ans / maxn / (bands-1) + 0.01)