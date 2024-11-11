import sys,bisect
from collections import deque

input=sys.stdin.buffer.readline

t=1
t=int(input())
for _ in range(t):
    n,S=map(int,input().split())
    edge=[[] for i in range(n)]
    for i in range(n-1):
        u,v,w,c=map(int,input().split())
        edge[u-1].append((v-1,w,c))
        edge[v-1].append((u-1,w,c))

    ans=[0]
    deq=deque(ans)
    parent=[-1]*n
    while deq:
        v=deq.popleft()
        for nv,w,c in edge[v]:
            if nv!=parent[v]:
                parent[nv]=v
                ans.append(nv)
                deq.append(nv)

    for v in range(n):
        edge[v]=[edge[v][i] for i in range(len(edge[v])) if edge[v][i][0]!=parent[v]]

    size=[0]*n
    ans=ans[::-1]
    for v in ans:
        for nv,w,c in edge[v]:
            size[v]+=size[nv]
        if len(edge[v])==0:
            size[v]=1

    s=0
    que1=[]
    que2=[]
    for v in range(n):
        for nv,w,c in edge[v]:
            s+=size[nv]*w
            if c==1:
                while w>=1:
                    minus=size[nv]*(w-w//2)
                    w//=2
                    que1.append(minus)
            else:
                while w>=1:
                    minus=size[nv]*(w-w//2)
                    w//=2
                    que2.append(minus)

    que1.sort(reverse=True)
    que2.sort(reverse=True)

    n,m=len(que1),len(que2)
    for i in range(1,m):
        que2[i]+=que2[i-1]
    que2=[0]+que2
    que1=[0]+que1

    ans=10**20
    id=m+1
    cum=0
    for i in range(n+1):
        test=i
        cum+=que1[i]
        while id>0 and que2[id-1]>=s-S-cum:
            id-=1
        if id!=m+1:
            test+=2*id
            ans=min(ans,test)

    print(ans)
