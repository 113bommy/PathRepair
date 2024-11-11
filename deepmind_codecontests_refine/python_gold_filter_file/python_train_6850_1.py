import sys
input=sys.stdin.buffer.readline
inputs=sys.stdin.buffer.readlines
sys.setrecursionlimit(10**9)
n,m=map(int,input().split())
edges=[[] for i in range(3+3*n)]
o=inputs()
s,T=map(int,o.pop().split())
for i in o:
    _,__=map(int,i.split())
    _*=3;__*=3
    edges[_].append(__+1)
    edges[_+1].append(__+2)
    edges[_+2].append(__)

from collections import deque
dq=deque([])
dq.append((3*s,0))
T*=3
seen=[0]*(3*n+3)
seen[3*s]=1
while dq:
    now,c=dq.popleft()
    if now==T :print(c//3);exit()
    for t in edges[now]:
        if seen[t]==0:
            dq.append((t,c+1))
            seen[t]=1
print("-1")
