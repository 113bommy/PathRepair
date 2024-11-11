N=int(input())
a=list(map(int,input().split()))
a_=sorted(a,key=lambda x:-x)
ans=0
from collections import Counter
c=Counter(a_)
for i in a_:
    if c[i]==0:
        continue
    c[i]-=1
    for n in range(i):
        if i<2**n:
            t=n
            break
        elif i==2**n:
            t=n+1
            break
    j=2**t-i
    if j in c and c[j]>0:
        ans+=1
        c[j]-=1
print(ans)