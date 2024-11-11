import math
def res():
    n,m=map(int,input().split())
    k=math.floor(math.log(m,2))
    i=1
    t=n
    f=1
    while i<=k:
        if t%m==0:
            f=0
            break
        t=t*2
        i=i+1
    if f==0:
        print("Yes")
    else:
        print("No")
    
res()