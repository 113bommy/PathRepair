import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**7)
mod=10**9+7
n=int(input())
edges=[[] for _ in range(n)]
for _ in range(n-1):
    x,y=map(int,input().split())
    edges[x-1].append(y-1)
    edges[y-1].append(x-1)
C=[[] for _ in range(n)]

def fill_C(v,par):
    for c in edges[v]:
        if c==par:
            continue
        C[v].append(c)
        fill_C(c,v)
fill_C(0,-1)

DP=[[-1,-1] for _ in range(n)]

def white(v):
    if DP[v][0]!=-1:
        return DP[v][0]
    res=1
    for c in C[v]:
        res*=white(c)+black(c)
        res%=mod
    DP[v][0]=res
    return res
def black(v):
    if DP[v][1]!=-1:
        return DP[v][1]
    res=1
    for c in C[v]:
        res*=white(c)
        res%=mod
    DP[v][1]=res
    return res

print((black(0)+white(0))%mod)