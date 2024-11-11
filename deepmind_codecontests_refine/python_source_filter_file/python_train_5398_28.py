def n0():return int(input())
def n1():return [int(x) for x in input().split()]
def n2(n):return [int(input()) for _ in range(n)]
def n3(n):return [[int(x) for x in input().split()] for _ in range(n)]

n,k=n1()
a=n1()

import itertools
ite=itertools.combinations(range(n),k)

ans=10**20
for line in ite:
    c=0
    b=a.copy()
    for i in range(1,k):
        if b[line[i]]<=b[line[i-1]]:
            plus=b[line[i-1]]-b[line[i]]+1
            b[line[i]]+=plus
            c+=plus
    ok=1
    for i in range(n):
        if b[i-1]<b[i]:
            ok+=1
        else:
            b[i]=b[i-1]
    if ok>=3:
        ans=min(ans,c)
print(ans)