# -*- coding: utf-8 -*-
import sys
from collections import defaultdict
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
input=lambda: sys.stdin.readline().rstrip()
YesNo=lambda b: bool([print('Yes')] if b else print('No'))
YESNO=lambda b: bool([print('YES')] if b else print('NO'))
int1=lambda x:int(x)-1

N,M=map(int,input().split())
edge=[[] for _ in range(N)]
for _ in range(M):
    a,b=map(int1,input().split())
    edge[a].append(b)

used=[False]*N
for i in range(N):
    if used[i]==True:
        continue
    stack=[i]
    path=[]
    while stack:
        v=stack.pop()
        if v>=0:
            used[v]=True
            path.append(v)
            for nv in edge[v]:
                if not used[nv]:
                    stack.append(~v)
                    stack.append(nv)
                else:
                    if nv in path:
                        path.append(nv)
                        break
            else:
                continue
            break
        else:
            path.pop()
    else:
        continue
    break
else:
    print(-1)
    exit()
cycle=path[path.index(path[0]):]
while True:
    s=set(cycle)
    next_cycle=[]
    for i,v in enumerate(cycle[:-1]):
        next_cycle.append(v)
        for nv in edge[v]:
            if nv==cycle[i+1]:
                continue
            if nv in s:
                next_cycle.extend(cycle[cycle.index(nv):])
                break
        else:
            continue
        break
    else:
        break
    cycle=[]
    ss=set()
    for v in next_cycle:
        if v in ss:
            vv=v
            break
        ss.add(v)
    f=False
    for v in next_cycle:
        if v==vv:
            cycle.append(v)
            if not f:
                f=True
            else:
                break
        elif f:
            cycle.append(v)
    
print(len(cycle)-1)
for v in cycle[:-1]:
    print(v+1)