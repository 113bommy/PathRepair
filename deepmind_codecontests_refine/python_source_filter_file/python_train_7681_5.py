N, K = map(int, input().split())
P = list(map(int, input().split()))
INF = float('inf')
num = 2**(N-1).bit_length()
segmin = [INF] * num*2
segmax = [-INF] * num*2
for i in range(N):
    segmin[num + i - 1] = P[i]
    segmax[num + i - 1] = P[i]
for i in range(num-2, -1, -1):
    segmin[i] = min(segmin[2*i+1], segmin[2*i+2])
    segmax[i] = max(segmax[2*i+1], segmax[2*i+2])

def query(seg, f, boundary, p, q):
    p += num-1
    q += num-2
    res=boundary
    while q-p>1:
        if p&1 == 0:
            res = f(res,seg[p])
        if q&1 == 1:
            res = f(res,seg[q])
            q -= 1
        p = p//2
        q = (q-1)//2
    if p == q:
        res = f(res,seg[p])
    else:
        res = f(f(res,seg[p]),seg[q])
    return res

ans = 1
for i in range(N-K):
    if not (P[i] < query(segmin, min, INF, i+1, i+K) and P[i+K] > query(segmax, max, -INF, i+1, i+K)):
        ans += 1

# 昇順にならんでいるケース
combo = 0
nord = 0
for i in range(1,N):
    if P[i] > P[i-1]:
        combo += 1
    else:
        combo = 0
    if combo >= K-1:
        nord += 1

print(ans - max(0, nord-1))
