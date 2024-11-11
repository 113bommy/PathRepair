from collections import deque
import sys
input=sys.stdin.readline
T=int(input())
for r in range(T):
    n,m=list(map(int,input().split()))
    ADL={i:set() for i in range(1,n+1)}

    for i in range(m):
        x,y=list(map(int,input().split()))
        ADL[x].add(y)
        ADL[y].add(x)

    to_visit=[True]*len(ADL)
    current=deque()
    current.append(1)
    parity=[False]*n
    to_visit[0]=False
    while current:
        vertex=current.popleft()
        for i in ADL[vertex]:
            if to_visit[i-1]:
                parity[i-1]=not parity[vertex-1]
                current.append(i)
                to_visit[i-1]=False
    if sum(parity)<n//2:
        s=set([i+1 for i in range(n) if parity[i]])
    else:
        s=set([i+1 for i in range(n) if not parity[i]])

    print(len(s))
    print(*s)
