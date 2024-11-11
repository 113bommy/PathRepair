from math import *
t=int(input())
for o in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=a.copy()
    b.sort()
    c=[]
    m=b[0]
    for i in range(n):
        if a[i]!=b[i]:
            c.append(a[i])
    if len(c)==0:
        print("YES")
    else:
        c.sort()
        l=len(c)
        f=1
        for i in range(l):
            if c[i]%m!=0:
                f=0
                break
        if f==0:
            print("NO")
        else:
            f=0
            for i in range(1,l):
                if gcd(c[0],c[i])==m:
                    f=1
                    break
            if f==1:
                print("YES")
            else:
                print("NO")