from math import *
t=int(input())
for _ in range(t):
    n,g,b=map(int,input().split())
    s=0
    if g>=b:
        s=n
    else:
        k = ceil(n / 2)
        if k%g==0:
            s=k+((k//g)-1)*b
        else:
            s=k+(k//g)*b

    print(max(s,n))





