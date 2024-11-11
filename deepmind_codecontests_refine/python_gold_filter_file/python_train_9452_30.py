n,m,p=map(int,input().split())
edge=[]
for i in range(m):
    a,b,c=map(int,input().split())
    edge.append((a,b,p-c))
INF=float('inf')
def bellmanford(s,n):
    d = [INF for i in range(n+1)]
    d[s]=0
    for i in range(n-1):
        for a,b,c in edge:
            if d[b]>d[a]+c:
                d[b]=d[a]+c
    for i in range(n-1):
         for a,b,c in edge:
            if d[b]>d[a]+c:
                d[b]=-INF
    return d
d=bellmanford(1,n)
if d[n]==-INF:
    print(-1)
elif d[n]>=0:
    print(0)
else:
    print(-d[n])