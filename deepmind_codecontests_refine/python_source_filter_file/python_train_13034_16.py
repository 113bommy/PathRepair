from functools import reduce
from operator import xor
t=int(input())
while t:
    t-=1
    n=int(input())
    l=list(map(int,input().split()))
    x=sum(l)
    y=reduce(xor,l)
    if x==2*y:
        print(0)
        print()
    else:
        a=0
        if x&1:
            a=1
            x+=a
        x>>=1
        y^=a
        if (x>y):
            k=1<<len(bin(x)[2:])
            a+=k
            x+=k>>1
            y^=k
        if (x==y):
            print(1)
            print(a)
        else:
            b=y-x
            print(3)
            print(a,b,b)