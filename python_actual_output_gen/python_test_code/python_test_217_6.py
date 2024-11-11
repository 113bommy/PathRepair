n,m=map(int,input().split())
e=[]
for i in range(m):
    e.append(list(map(int,input().split())))
ans=0
for i in range(m):
    g=[[] for _ in range(n)]
    for j in range(m):
        if i==j:
            continue
        g[e[j][0]-1].append(e[j][1])
        g[e[j][1]-1].append(e[j][0])
    visited=[0]*n
    visited[0]=1
    q=[1]
    while len(q)>0:
        a=pop(q)
        visited[a-1]=1
        for k in g[a-1]:
            if visited[k-1]==0:
                q+=[k]
    if sum(visited)!=n:
        ans+=1
print(ans)
                    
