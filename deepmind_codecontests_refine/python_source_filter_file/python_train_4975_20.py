from collections import deque
n=int(input())
g=[[] for i in range(n)]
for i in range(n-1):
    a,b=map(int,input().split())
    a-=1
    b-=1
    g[a].append(b)
    g[b].append(a)
v=[-1]*n
v[0]=0
q=deque([0])
while q:
    p=q.popleft()
    for i in g[p]:
        if v[i]==-1:
            v[i]=1-v[p]
            q.append(i)
z=0
for i in v:
    if i==0:
        z+=1
ans=[0]*n
if z<=n//3:
    j=3
    for i in range(n):
        if v[i]==0:
            ans[i]=j
            j+=3
    j=1
    for i in range(n):
        if ans[i]==0:
            ans[i]=j
            j+=1
            if j%3==0 and j//3<=z:
                j+=1
    print(*ans)
elif n-z<=n//3:
    j=3
    for i in range(n):
        if v[i]==1:
            ans[i]=j
            j+=3
    j=1
    for i in range(n):
        if ans[i]==1:
            ans[i]=j
            j+=1
            if j%3==0 and j//3<=n-z:
                j+=1
    print(*ans)
else:
    o=1
    t=2
    tt=3
    for i in range(n):
        if v[i]==0 and o<=n:
            ans[i]=o
            o+=3
        elif v[i]==0:
            ans[i]=tt
            tt+=3
        if v[i]==1 and t<=n:
            ans[i]=t
            t+=3
        elif v[i]==1:
            ans[i]=tt
            tt+=3
    print(*ans)