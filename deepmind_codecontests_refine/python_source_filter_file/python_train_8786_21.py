from sys import stdin,stdout
from collections import Counter
from itertools import permutations
import bisect
import math

I=lambda: map(int,stdin.readline().split())
I1=lambda: stdin.readline()
#(a/b)%m =((a%m)*pow(b,m-2)%m)%m

n=int(I1())
a=list(I())
x,y=I()
p,f=0,0
for i in range(n-1,-1,-1):
    if p>=x and p<=y:
        break
    p+=a[i]
f=sum(a)-p 
if f>=x and f<=y:
    print(i+2)
else:
    for j in range(i-2,-1,-1):
        if p>=x and p<=y and f>=x and f<=y:
            print(j+1)
            exit()
        p+=a[j]
        f-=a[j]
    print(0)

