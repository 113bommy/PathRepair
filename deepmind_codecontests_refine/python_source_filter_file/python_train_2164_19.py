import sys,math,copy,queue,itertools,bisect,collections
from heapq import *
LI = lambda : [int(x) for x in sys.stdin.readline().split()]
INF = 10**12

N,M,S = LI()
if S > N * 50:
    S = N * 50
root = [[] for _ in range(N)]
for _ in range(M):
    u,v,a,b = LI()
    root[u-1].append((v-1,a,b))
    root[v-1].append((u-1,a,b))
city = [LI() for _ in range(N)]

dp = [[INF] * (N*50+1) for _ in range(N)]
dp[0][S] = 0

hq = [[0,0,S]]
heapify(hq)

while hq:
    tm,pos,coin = heappop(hq)

    c = coin
    t = tm
    if c < N * 50:
        c += city[pos][0]
        c = min(c, N * 50)
        t += city[pos][1]
        if dp[pos][c] > t:
            dp[pos][c] = t
            heappush(hq,[t,pos,c])

    for p,a,b in root[pos]:
        c = coin - a
        if c >= 0:
            if dp[p][c] > tm + b:
                dp[p][c] = tm + b
                heappush(hq,[tm+b,p,c])

for i in range(1,N):
    print(min(dp[i]))


