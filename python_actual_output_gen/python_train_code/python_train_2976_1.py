def case(mid):
    elems,length=[],0
    for i,x in enumerate(d):
        item=d[x]//mid
        length+=item
    return length
n,k=map(int,input().split())
lst=[*map(int,input().split())]
d={}
for i,x in enumerate(lst):
    if d.get(x)==None:d[x]=0
    d[x]+=1
i,j=1,n
while i+1<j:
    mid=(i+j)//2
    leng=case(mid)
    if leng>=k:i=mid
    else:j=mid
if case(j)>=k:res=j
else:res=i
result=[]
ex=result.extend
for i,x in enumerate(d):
    ex([x]*(d[x]//res))
print(*result)