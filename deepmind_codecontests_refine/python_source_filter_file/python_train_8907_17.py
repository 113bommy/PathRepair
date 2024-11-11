from math import gcd
from bisect import bisect
a,b=map(int,input().split())

d=gcd(a,b)
c=int(d**0.5)
m=[]
for i in range(1,c+1):
    if d%i==0:
        m.append(i)
        m.append(d//i)
m.sort()

n=int(input())
for i in range(n):
    c,d=map(int,input().split())
    e=bisect(m,c)
    f=bisect(m,d)
    y=0
    for i in range(f-1,e-1,-1):
        if m[i]>=c and m[i]<=d:
            print(m[i])
            y=1
            break
    if y==0:
        print("-1")
        
    