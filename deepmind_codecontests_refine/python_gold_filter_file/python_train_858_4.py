import sys
from collections import defaultdict,deque
input=sys.stdin.readline

for _ in range(int(input())):
    n=int(input())
    g=defaultdict(list)
    for i in range(n-1):
        u,v=map(int,input().split())
        g[u].append(v)
        g[v].append(u)

    d=[1]*(n+1)
    p=[0]*(n+1)
    l=[10**6]*(n+1)
    
    q=deque([1])
    v=[0]*(n+1)
    v[1]=1
    rec=[]
    c=defaultdict(list)
    while q:
        x=q.popleft()
        rec.append(x)
        for i in g[x]:
            if v[i]==0:
                v[i]=1
                p[i]=x
                c[x].append(i)
                q.append(i)
    rec.reverse()

    for i in rec:
        for j in c[i]:
            d[i]+=d[j]

    x=max(d)
    for i in range(1,n+1):
        mm=-1
        for j in c[i]:
            mm=max(mm,d[j])
        mm=max(mm,x-d[i])
        l[i]=mm

    m=min(l)
    cnt=l.count(m)
    if cnt==1:
        print(1,c[1][0])
        print(1,c[1][0])
    else:
        for i in range(1,n+1):
            if l[i]==m:
                break
        for j in range(i+1,n+1):
            if l[j]==m:
                break
        m=10**9
        mi=-1
        for k in g[j]:
            if k==i:
                continue
            if m>d[k]:
                m=d[k]
                mi=k
        print(j,mi)
        print(i,mi)