def case(mid):
    res=0
    for i,x in enumerate(d):
        res+=(d[x]//mid)
    return res
n,m=map(int,input().split())
lst=list(map(int,input().split()))
d={}
for i,x in enumerate(lst):
    if d.get(x)==None:d[x]=0
    d[x]+=1
l,r=0,max(d.values())
while l+1<r:
    mid=(l+r)//2
    res=case(mid)
    if res<=n:r=mid
    else:l=mid
if case(r)>=n:print(r)
else:print(l)