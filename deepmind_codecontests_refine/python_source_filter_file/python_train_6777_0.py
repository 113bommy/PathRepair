import math
from collections import defaultdict
def power4(x):
    lo, hi=0, int(1e5)
    while lo+1<hi:
        m = (lo+hi)>>1
        p=m*m*m*m
        if p==x:
            return m
        elif p<x:
            lo=m
        else:
            hi=m
    return -1;
def power3(x):
    lo, hi=0, int(1e7)
    while lo+1<hi:
        m = (lo+hi)>>1
        p=m*m*m
        if p==x:
            return m
        elif p<x:
            lo=m
        else:
            hi=m
    return -1;
def val():
    return 0
n=int(input())
d=defaultdict(val)
lef=defaultdict(val)
a=[]
for i in range(n):
    x=int(input())
    p=power4(x)
    if p!=-1:
        d[p]+=4
        continue
    p=int(math.sqrt(x))
    if p*p==x:
        d[p]+=2
        continue
    p=power3(x)
    if p!=-1:
        d[p]+=3
        continue
    
    lef[x]+=1
    a.append(x)
ans=1
MOD=998244353
for x in a:
    p1=-1
    p2=-1
    for y in a:
        if x==y:
            continue
        g=math.gcd(x,y)
        if g!=1:
            p1=g
            p2=x/g
            break
    if p1!=-1:
        lef[x]=0
        d[p1]+=1
        d[p2]+=1
for t, v in lef.items():
    ok=False
    if v==0:
        continue
    for key in d.keys():
        if t%key==0:
            d[key]+=v
            d[t//key]+=v
            ok=True
            break
    if not ok:
        ans = ans*pow(v+1, 2, MOD)
        ans %=MOD


for t, v, in d.items():
    ans=ans*(v+1)
    ans%=MOD
print(ans, flush=True)

