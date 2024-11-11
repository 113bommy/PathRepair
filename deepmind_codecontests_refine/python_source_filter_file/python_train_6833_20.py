from math import*
n,k=(int(x)for x in input().split())
if k==1:
    print(k)
else:
    ans=0
    while n!=0:
        ans+=1
        n//=2
    print(2**ans-1)