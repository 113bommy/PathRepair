import sys
input = sys.stdin.readline
from collections import *

def bfs(s):
    dist = [-1]*N
    dist[s] = 0
    q = deque([s])
    
    while q:
        v = q.popleft()
        
        for nv in G[v]:
            if dist[nv]==-1:
                dist[nv] = dist[v]+1
                q.append(nv)
    
    return dist

N = int(input())
G = [[] for _ in range(N)]

for _ in range(N-1):
    a, b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

dist = bfs(0)
M = -1

for i in range(N):
    if dist[i]>M:
        M = dist[i]
        s = i

d = max(bfs(s))+1
dp = [False]*(d+1)
dp[1] = True

for i in range(3, d+1):
    dp[i] |= not dp[i-1]
    dp[i] |= not dp[i-2]

if dp[d]:
    print('First')
else:
    print('Second')