n,m=map(int,input().split())
g=[set()for i in range(n+1)]
for i in range(m):
    a,b=map(int,input().split())
    g[a].add(b)
    g[b].add(a)
ans=0
while True:
    remove=set()
    for i in range(1,n+1):
        if len(g[i])==1:remove.add(g[i].pop())
    if len(remove)==0:break
    ans+=1
    for i in range(1,n+1):g[i]-=remove
print(ans)