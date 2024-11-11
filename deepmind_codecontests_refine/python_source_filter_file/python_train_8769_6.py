from collections import *
from bisect import *
from math import *
from heapq import *
import sys
input=sys.stdin.readline
t=1
def su(n):
    if(n<=0):
        return 0
    return ((n*(n+1))//2)
while(t):
    t-=1
    n,x=map(int,input().split())
    a=list(map(int,input().split()))
    a=a+a
    preh=[su(a[0])]
    for i in range(1,2*n):
        preh.append(preh[-1]+su(a[i]))
    days=[a[0]]
    for i in range(1,2*n):
        days.append(days[-1]+a[i])
    r=0
    pre=0
    for i in range(n):
        r1=0
        pos=bisect_left(days,pre+x)
        if(pos-i==0):
            le=a[i]-x
            r=max(r,su(a[i])-su(le))
        else:
            r1=preh[pos-1]-preh[i]
            newx=x-days[pos-1]+days[i]
            if(newx>a[pos]):
                limi=su(a[pos])
                limi1=su(a[i])-su(a[i]-x+a[pos])
            else:
                limi=su(a[pos])-su(a[pos]-newx)
                limi1=0
            r1+=limi+limi1
        pre+=a[i]
        r=max(r,r1)
    print(r)
