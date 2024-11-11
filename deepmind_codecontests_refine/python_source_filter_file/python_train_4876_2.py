import sys
def MI(): return map(int,sys.stdin.readline().rstrip().split())

N,M = MI()
S,T = MI()
edges = [[] for _ in range(N+1)]
edges2 = []
for _ in range(M):
    U,V,D = MI()
    edges[U].append((V,D))
    edges[V].append((U,D))
    edges2.append((U,V,D))
    edges2.append((V,U,D))

mod = 10**9+7

from heapq import heappop,heappush

distS = [(10**18,0)]*(N+1)  # (最短距離,経路数)
distS[S] = (0,1)
qS = []
heappush(qS,(0,S))
vS = [False]*(N+1)
while qS:
    d,i = heappop(qS)
    if vS[i]:
        continue
    vS[i] = True
    for j,d in edges[i]:
        if vS[j]:
            continue
        if distS[j][0] > distS[i][0] + d:
            distS[j] = (distS[i][0] + d,distS[i][1])
            heappush(qS,(distS[i][0] + d,j))
        elif distS[j][0] == distS[i][0] + d:
            distS[j] = (distS[j][0],distS[j][1]+distS[i][1])
            heappush(qS,(distS[i][0] + d,j))

distT = [(10**18,0)]*(N+1)
distT[T] = (0,1)
qT = []
heappush(qT,(0,T))
vT = [False]*(N+1)
while qT:
    d,i = heappop(qT)
    if vT[i]:
        continue
    vT[i] = True
    for j,d in edges[i]:
        if vT[j]:
            continue
        if distT[j][0] > distT[i][0] + d:
            distT[j] = (distT[i][0] + d,distT[i][1])
            heappush(qT,(distT[i][0] + d,j))
        elif distT[j][0] == distT[i][0] + d:
            distT[j] = (distT[j][0],distT[j][1]+distT[i][1])
            heappush(qT,(distT[i][0] + d,j))

a,b = distS[T]  # SからTまでの最短距離,経路数
ans = b**2 % mod

# 頂点で出くわす場合
if a % 2 == 0:
    for i in range(1,N+1):
        if distS[i][0] == distT[i][0] == a//2:
            ans -= (distS[i][1]*distT[i][1])**2
            ans = mod

# 辺上で出くわす場合
for i in range(2*M):
    U,V,D = edges2[i]
    if distS[U][0] < (a+1)//2 and distT[V][0] < (a+1)//2 and a == distS[U][0] + D + distT[V][0]:
        ans -= (distS[U][1]*distT[V][1])**2
        ans %= mod

print(ans)
