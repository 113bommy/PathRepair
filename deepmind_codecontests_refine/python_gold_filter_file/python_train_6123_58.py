import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
mod=10**9+7

N=int(input())
XY=[list(map(int,input().split())) for i in range(N-1)]

EDGELIST=[[] for i in range(N+1)]

for x,y in XY:
    EDGELIST[x].append(y)
    EDGELIST[y].append(x)

check=[0]*(N+1)

from collections import deque
QUE=deque([1])

EDGE1=[[] for i in range(N+1)]

while QUE:
    x=QUE.pop()
    if check[x]==1:
        continue

    for to in EDGELIST[x]:
        if check[to]==1:
            continue
        else:         
            QUE.append(to)
            EDGE1[x].append(to)

    check[x]=1
        

def ANS(n):
    if EDGE1[n]==[]:
        return 1,1
    else:
        b=1
        w=1
        for to in EDGE1[n]:
            x,y=ANS(to)
            b=b*y%mod
            w=w*(x+y)%mod

        return b,w

print(sum(ANS(1))%mod)