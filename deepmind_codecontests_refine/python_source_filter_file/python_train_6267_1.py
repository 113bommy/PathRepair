x=int(input())
from math import ceil
s=list(map(int,input().split()))
id=[]
for n in range(x):
    if s[n]:
        id.append(n)

if len(id)==1:
    print(-1)
    exit(0)

sm=len(id)
res=1e9
divs=set()
for n in range(2,int(sm**.5)+1):
    if sm%n==0:
        divs.add(n)
        divs.add(sm//n)
divs.add(sm)
    
dv=[]
for n in divs:
    dv.append(n)
res=1e9
for divisor in dv:
    tm=0
    md=divisor//2
    for n in range(0,sm,divisor):
        mid=id[n+md]
        for k in range(n,n+divisor):
            tm+=abs(id[k]-mid)
    res=min(res,tm)

print(res)
        
