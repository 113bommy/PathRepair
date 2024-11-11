import sys
input = sys.stdin.readline
from collections import defaultdict,deque
from itertools import combinations
from heapq import heappush, heappop

xs,ys,xt,yt = map(int,input().split())
N = int(input())
xyr = [list(map(int,input().split())) for i in range(N)]

#import random
#N = 1000
#xs,ys = (-10**9,-10**9)
#xt,yt = (10**9, 10**9)
#xyr = [[random.randint(-10**9, 10**9),random.randint(-10**9, 10**9),random.randint(1,10)] for i in range(N)]
#xyr = [[2*i,2*i,1] for i in range(N)]

xyr = [[xs,ys,0]] + xyr + [[xt,yt,0]]

cost = {}
for s in range(0,N+1):
    for t in range(s+1,N+2):
        x1,y1,r1 = xyr[s]
        x2,y2,r2 = xyr[t]
        R = pow((x2-x1)**2+(y2-y1)**2,0.5)
        c = max(0, R-r1-r2)
        cost[(s,t)] = c
        cost[(t,s)] = c

h = [(0,0)]
dist = [10**15] * (N+2)
dist[0] = 0
while h:
    v,d = heappop(h)
    if dist[v] < d:
        continue
    for nv in range(N+2):
        if v == nv:
            continue
        temp = d + cost[(v,nv)]
        if temp < dist[nv]:
            dist[nv] = temp
            heappush(h, (nv,temp))

print(dist[N+1])






