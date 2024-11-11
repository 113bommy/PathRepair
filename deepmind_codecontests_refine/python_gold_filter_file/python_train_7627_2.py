from collections import defaultdict
n,k=map(int,input().split())
ma=0
a=[]
graph=[]
factories=0
ports=0
f=[False]*(n+1)
p=[False]*(n+1)
for i in range(k):
    u,v,d=map(int,input().split())
    graph.append([u,v,d])
    ma=max(ma,d)
s=0
l=ma
ans=-1
while(s<=l):
    m=(s+l)//2
    factories = 0
    ports = 0
    f = defaultdict(bool)
    p = defaultdict(bool)
    for i in range(k):
        u,v,d=graph[i]
        if d<=m:
            if not f[u]:
                f[u]=True
                factories+=1
            if not p[v]:
                p[v]=True
                ports+=1
    if factories==n and ports==n:
        ans=m
        l=m-1
    else:
        s=m+1
print(ans)