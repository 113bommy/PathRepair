n=int(input())
A=list(map(int,input().split()))

from bisect import bisect
cums=[0]
for a in A:
    cums.append(cums[-1]+a)

lmn=[]
lmx=[]
for i in range(2,n-1):
    j=bisect(cums,cums[i]//2)
    a1,b1=cums[j],cums[i]-cums[j]
    a2,b2=cums[j-1],cums[i]-cums[j-1]
    if abs(a1-b1)<abs(a2-b2):
        lmn.append(min(a1,b1))
        lmx.append(max(a1,b1))
    else:
        lmn.append(min(a2,b2))
        lmx.append(max(a2,b2))
A.reverse()
cums=[0]
for a in A:
    cums.append(cums[-1]+a)

rmn=[]
rmx=[]
for i in range(2,n-1):
    j=bisect(cums,cums[i]//2)
    a1,b1=cums[j],cums[i]-cums[j]
    a2,b2=cums[j-1],cums[i]-cums[j-1]
    if abs(a1-b1)<abs(a2-b2):
        rmn.append(min(a1,b1))
        rmx.append(max(a1,b1))
    else:
        rmn.append(min(a2,b2))
        rmx.append(max(a2,b2))
rmn.reverse()
rmx.reverse()
ans=float('inf')
for ln,lx,rn,rx in zip(lmn,lmx,rmn,rmx):
    d=max(lx,rx)-min(ln,rn)
    ans=min(ans,d)
print(ans)


