from itertools import *
n,m,x=map(int,input().split())
L=[list(map(int,input().split())) for _ in range(n)]
a=10**6
for i in range(1,n+1):
    for j in combinations(L,i):
        b=[0]*(m+1)
        for k in j:
            b=[b[i]+k[i] for i in range(m+1)]
        if all(i>=x for i in b[1:]):
            a=min(a,b[0])
print(-1 if a==10**6 else a)