import math
for i in range(int(input())):
    k,n,a,b=map(int,input().split())
    x=math.ceil(k//b)
    x-=1
    if x<n:
        print(-1)
    else:
        z=k-b*n-1
        print(min(n,z//(a-b)))