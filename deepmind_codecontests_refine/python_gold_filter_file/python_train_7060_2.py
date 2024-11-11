n=int(input())
l=[0]+list(map(int,input().split()))
from itertools import accumulate
l=list(accumulate(l))
from bisect import bisect, bisect_left, bisect_right
ans=10**15
for i in range(2,n-1):
    x=bisect_left(l,l[i]//2)
    p1=l[x]
    p2=l[x-1]
    if abs(l[i]-p1*2)>=abs(l[i]-p2*2):
        p=p2
    else:
        p=p1
    q=l[i]-p
    x=bisect_left(l,(l[n]-l[i])//2+l[i])
    r1=l[x]-l[i]
    r2=l[x-1]-l[i]
    if abs(l[n]-l[i]-r1*2)>=abs(l[n]-l[i]-r2*2):
        r=r2
    else:
        r=r1
    s=l[n]-l[i]-r
    ans=min(ans,max(p,q,r,s)-min(p,q,r,s))
print(ans)