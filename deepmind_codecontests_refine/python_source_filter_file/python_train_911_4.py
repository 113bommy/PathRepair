# -*- coding: utf-8 -*-
import sys
from collections import deque
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
input=lambda: sys.stdin.readline().rstrip()
YesNo=lambda b: bool([print('Yes')] if b else print('No'))
YESNO=lambda b: bool([print('YES')] if b else print('NO'))
int1=lambda x:int(x)-1

N=int(input())
M=N**2
P=tuple(map(int1,input().split()))
d=[0]*M
for i in range(N):
    for j in range(N):
        d[i*N+j]=min(min(i,N-1-i),min(j,N-1-j))
used=[1]*M
ans=0
que=deque()
for p in P:
    ans+=d[p]
    used[p]=0
    que.append(p)
    while que:
        x=que.popleft()
        for ddx in (-1,1,-N,N):
            nx=x+ddx
            if 0<=nx<M:
                if used[x]==0 and d[nx]-d[x]>=1:
                    d[nx]-=1
                    que.append(nx)
                elif used[x]==1 and d[nx]-d[x]>=2:
                    d[nx]-=1
                    que.append(nx)
print(ans)

