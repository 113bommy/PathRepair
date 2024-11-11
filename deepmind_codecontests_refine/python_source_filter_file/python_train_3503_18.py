from math import *
n=int(input())
k=int(input())
a=int(input())
b=int(input())
if k==1:
    print(a*(n-1))
else:
    ans=0
    while n>=k:
        ans+=(n%k)*a
        n-=n%k
        dif=n-n/k
        if dif*a<=b:
            ans+=dif*a
        else:
            ans+=b
        n=n/k
    ans+=(n-1)*a
    print(ans)
