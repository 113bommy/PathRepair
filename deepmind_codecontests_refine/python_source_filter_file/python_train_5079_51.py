import math
n,d,a=map(int,input().split())
XH=[[int(i)for i in input().split()] for _ in range(n)]
XH.sort(key=lambda x:x[0])
ans=0
l=0
before=0
T=[0]*n
for i,xh in enumerate(XH):
    x,h=xh
    while XH[l][0]+2*d<x:
        before-=T[l]
        l+=1
    h-=before*a
    if h<=0:
        continue
    T[i]=math.ceil(h//a)
    ans+=T[i]
    before+=T[i]
print(ans)