import sys
from bisect import bisect_left, bisect_right
input = sys.stdin.buffer.readline

n, h, m, k = map(int, input().split())
p, trm = m//2, []
for i in range(n):
    a, b = map(int, input().split())
    trm.append((b%p, i+1))
trm.sort()
tls = [t for t, _ in trm]

mxn, mxt, mxrng = 0, 0, []
for t, _ in trm:
    rng = []
    if t+k <= p:
        rng.append((0, t))
        rng.append((t+k, p))
    else:
        rng.append((t+k-p, t))
    
    cc = 0
    for a, b in rng:
        pa = bisect_left(tls, a)
        pb = bisect_right(tls, b)
        cc += pb-pa
    
    if cc > mxn: mxt, mxn, mxrng = t+k, cc, rng

used = [0]*(n+1)
for a, b in mxrng:
    pa = bisect_left(tls, a)
    pb = bisect_right(tls, b)
    for u in range(pa, pb):
        used[trm[u][1]] = 1
cancel = [u for u in range(1, n+1) if not used[u]]

print(n-mxn, mxt)
print(*cancel)

