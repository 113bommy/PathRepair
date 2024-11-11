from sys import stdin,stdout
from itertools import accumulate
nmbr=lambda:int(stdin.readline())
lst=lambda:list(map(int,stdin.readline().split()))
for _ in range(1):#nmbr())
    n,w,b=lst()
    a=lst();ans=0
    for i in range(n):
        if a[i]==2:
            if a[n-i-1]==0:
                a[i]=0
                ans+=w
            elif a[n-i-1]==1:
                a[i]=1
                ans+=b
            else:
                if w<=b:
                    ans+=w if i==(n-i-1) else 2*w
                    a[i]=a[n-i-1]=0
                else:
                    ans+=b if i==(n-i-1) else 2*b
                    a[i]=a[n-i-1]=1
        elif a[i]!=a[n-i-1] and a[n-i-1]!=2:
            ans=-1
            break
    print(ans)