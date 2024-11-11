import math
n,k=list(map(int,input().split()))
if k<=n+1:
    print(min(0,math.ceil(k/2)-1))
else:
    k=2*n+2-k
    print(min(0,math.ceil(k/2)-1))