n=int(input())
G=[[] for i in range(n)]
for i in range(n-1):
    a,b,c=[int(v)-1 for v in input().split()]
    c+=1
    G[a-1].append((b-1,c))
    G[b-1].append((a-1,c))
q,k=[int(v) for v in input().split()]
k=k-1
stack=[k]
dis=[-1]*n
dis[k]=0
while stack!=[]:
    now=stack.pop()
    d=dis[now]
    for i in G[now]:
        if dis[i[0]]==-1:
            dis[i[0]]=d+i[1]
            stack.append(i[0])
for i in range(q):
    x,y=[int(v)-1 for v in input().split()]
    print(dis[x]+dis[y])

