from sys import stdin,stdout
from math import ceil
nmbr = lambda: int(stdin.readline())
lst = lambda: list(map(int,stdin.readline().split()))
def fn(a,b):
    op=0
    while max(a,b)<m:
        a1=max(a,b)+min(a,b)
        b1=max(a,b)
        a,b=a1,b1
        op+=1
    return op
for _ in range(1):#nmbr()):
    a,b,m=lst()
    if a>b:a,b=b,a
    if max(a,b)>=m:
        print(0)
        continue
    if a<=0 and b<=0:
        if (a+b)>=m:
            print(0)
        else:print(-1)
        continue
    if a>0 and b>0:
        print(fn(a,b))
        continue
    if a<=0 and b>0:
        terms=ceil(-a/b)
        start=a+terms*b
        print(terms+fn(start,b))
        continue
    print(-1)