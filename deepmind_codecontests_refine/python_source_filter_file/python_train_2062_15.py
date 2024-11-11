#!/usr/bin/env python3
#abc126 e

import sys
sys.setrecursionlimit(100000)
N,M = list(map(int,input().split()))
XYZ = [list(map(int,input().split())) for _ in range(M)]

G = [[] for _ in range(N)]

for i in XYZ:
    G[i[0]-1].append(i[1])
    G[i[1]-1].append(i[0])

check = [False for _ in range(N)]#各頂点を訪問したかどうか

def DFS(G,s):
    check[s-1] = True
    for i in G[s-1]:
        if not check[i-1]:
            DFS(G,i)
ans = 0
for i in range(N):
    if not check[i]:
        DFS(G,i+1)
        ans += 1
print(ans)
