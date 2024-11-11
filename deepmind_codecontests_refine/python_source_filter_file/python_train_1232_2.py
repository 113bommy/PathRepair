import sys
sys.setrecursionlimit(10**5)
n=int(input())
G=[[]for i in range(n+1)]
for i in range(n-1):
    a, b, c = map(int,input().split())
    G[a] += (b,c),
    G[b] += (a,c),
q, k = map(int,input().split())
d = [0]*(n+1) #kから各点への距離
def f(v,p,u): #v:今見ているとこ p:一つ前に見たとこ u:kからの距離
    d[v] = u
    for t, c in G[v]:
        if p != t:
            f(t,v,u+c)
f(k,0,0)
for i in range(q):
    x, y = map(int,input().split())
    print(d[x]+d[y])