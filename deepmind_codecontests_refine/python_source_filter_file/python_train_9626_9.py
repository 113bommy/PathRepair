from bisect import bisect_right
from math import inf

n=int(input())
a=sorted([int(x) for x in input().split()])
m=int(input())
b=sorted([int(x) for x in input().split()])
p=-inf
tt=[]
for i in a+b+[0]:
    x=n-bisect_right(a,i)
    y=m-bisect_right(b,i)
    if (x-y)>p:
        p=(x-y)
        tt=[x,y]

print(*[n*2+tt[0],m*2+tt[1]],sep=":")