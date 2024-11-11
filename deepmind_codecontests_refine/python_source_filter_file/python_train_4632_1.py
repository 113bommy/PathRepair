from sys import stdin,stdout
from collections import Counter
nmbr = lambda: int(input())
lst = lambda: list(map(int, input().split()))
for _ in range(1):#nmbr()):
    n,k,pp,x,y=lst()
    a=lst()
    d=Counter(a)
    added=n-k-1
    a+=[y]*(n-k)
    a.sort()
    sm=sum(a)
    p=n//2-1;f=1
    # print(a)
    while p>=0 and sm>x and added>0:
        if a[p]==y:
            sm-=a[p]-1
            a[p]=1
            added-=1
            p-=1
    # print(a)
    for v11 in a:
        if (1<=v11<=pp):continue
        f=0
        break
    a.sort()
    if a[n//2]<y or sum(a)>x:
        f=0
    if f==0:
        print(-1)
        continue
    d1=Counter(a)
    mp={}
    ans=[]
    # print(d)
    # print(d1)
    for k,v in d.items():
        mp[k]=mp.get(k,0)+v
    for k,v in d1.items():
        mp[k]=mp.get(k,0)-v
    for k,v in mp.items():
        if v!=0:
            ans+=[k]*abs(v)
    print(*ans)