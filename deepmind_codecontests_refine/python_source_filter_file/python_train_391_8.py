import sys
sys.setrecursionlimit(10**5+1)

def cur(p):
    for i in x[p]:
        if rank[i]==-1:
            rank[i]=rank[p]+1
            par[i]=p
            cur(i)

def cur2(p):
    if spar[p]==-1:
        spar[p]=cur2(par[p])
    return spar[p]




n,u,v=map(int,input().split())
u,v=u-1,v-1
x=[[] for i in range(n)]

for i in range(n-1):
    a,b=map(int,input().split())
    a,b=a-1,b-1
    x[a].append(b)
    x[b].append(a)

rank=[-1 for i in range(n)]
rank[u]=0
par=[-1 for i in range(n)]

cur(u)

spar=[-1 for i in range(n)]
i=v
while i!=u:
    spar[i]=i
    i=par[i]
spar[u]=u


for p in range(n):
    cur2(p)

ans=rank[v]-1
for i in range(n):
    z=rank[v]-rank[spar[i]]*2
    if z>0:
        ans=max(0,rank[i]+z-1)
print(ans)