from collections import defaultdict
t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    d1=defaultdict(int)
    for j in range(n):
        if j&1==0:
            d1[(a[j],0)]+=1
        else:
            d1[(a[j],1)]+=1
    a.sort()
    d2=defaultdict(int)
    for j in range(n):
        if j&1==0:
            d2[(a[j],0)]+=1
        else:
            d2[(a[j],1)]+=1
    s=set(a)
    ans='YES'
    for p in s:
        if d1[(p,0)]!=d2[(p,0)] or d1[(p,1)]!=d2[(p,1)]:
            ans='NO'
            break

    print(ans,d1,d2)