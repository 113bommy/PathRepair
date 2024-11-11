import math
n,k=map(int,input().split())
if k==0:
    print(0,0)
elif k==1:
    print(1,2)
elif n==k:
    print(0,0)
elif n-1==k:
    print(1,1)
else:
    x=n//3
    if k<=x:
        print(1,2*k)
    else:
        print(1,n-k)
    