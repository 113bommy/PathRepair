import sys
sys.setrecursionlimit(10**8)

N,M = map(int,input().split())
src = [tuple(map(lambda x:int(x)-1,input().split())) for i in range(M)]
Q = int(input())
qs = [tuple(map(int,input().split())) for i in range(Q)]

es = [[] for i in range(N)]
for a,b in src:
    es[a].append(b)
    es[b].append(a)

cs = [0] * N
depth = [0] * N

def rec(v,d,c,pv):
    if d < depth[v]: return
    depth[v] = d
    if cs[v]==0:
        cs[v] = c
    if d==0: return
    for to in es[v]:
        if to==pv: continue
        rec(to,d-1,c,v)

for v,d,c in qs[::-1]:
    rec(v-1,d,c,-1)

print(*cs, sep='\n')