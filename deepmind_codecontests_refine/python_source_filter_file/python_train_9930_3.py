n,m=map(int,input().split())
graph={}
for i in range(1,n+1):
    graph[i]=[]
for i in range(m):
    u,v=map(int,input().split())
    graph[u].append(v)
    graph[v].append(u)
c=0
d=0
#print(graph)
for i in range(1,n+1):
    if len(graph[i])==1:
        c=c+1
    elif len(graph[i])>=2:
        d=d+1
if m==n-1 and c==2 and d==n-2:
    print("bus topology")
elif c==0 and d==n and m==n:
    print("ring topology")
elif c==n-1 and d==1 and m==n:
    print("star topology")
else:
    print("unknown topology")
                        
