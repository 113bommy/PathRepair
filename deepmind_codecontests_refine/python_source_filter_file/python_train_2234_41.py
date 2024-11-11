from math import ceil
n,m=(map(int,input().split()))
t=ceil(n/2)
if t%m==0:
    print(m)
else:
    t+=(m-t%m)
    if t>n:
        print(-1)
    else:
        print(t)
