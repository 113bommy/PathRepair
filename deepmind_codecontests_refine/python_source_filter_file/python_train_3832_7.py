n=int(input())
tree=[[]for _ in range(n+1)]
for _ in range(n-1):
    u,v,w=map(int,input().split())
    tree[u].append([v,w])
    tree[v].append([u,w])
d=[-1]*(n+1)
d[1]=0
q=[1]
while q:
    now=q.pop()
    for n_i,n_l in tree[now]:
        if d[n_i]==-1:
            d[n_i]=d[now]+[n_l]
            q.append(n_i)
for l in d[1:]:
    print(l%2)