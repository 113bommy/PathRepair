from collections import deque
n=int(input())
g=[[] for i in range(n)]
for i in range(n):
    p=list(str(input()))
    for j in range(n):
        if p[j]=='1':
            g[i].append(j)
q=deque([0])
v=[-1]*n
v[0]=0
while q:
    p=q.popleft()
    for i in g[p]:
        if v[i]==-1:
            v[i]=1-v[p]
            q.append(i)
        else:
            if v[i]!=1-v[p]:
                print(-1)
                exit()
ans=0
for s in range(n):
    q=deque([s])
    v=[0]*n
    v[s]=1
    while q:
        p=q.popleft()
        for i in g[p]:
            if v[i]==0:
                v[i]=1+v[p]
                q.append(i)
    ans=max(ans,max(v))
print(ans)
