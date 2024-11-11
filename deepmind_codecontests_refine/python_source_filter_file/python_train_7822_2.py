from sys import *
from math import *
n=int(stdin.readline())
a = list(map(int, stdin.readline().split()))
x=0
s=[]
j=0
l=n-1
while j<=l:
    f=0
    if a[j]<a[l]:
        if a[j]>x:
            x=a[0]
            s.append("L")
            f=1
            j+=1
        elif a[l]>x:
            x=a[l]
            l-=1
            s.append("R")
            f=1
    else:
        if a[l]>x:
            x = a[l]
            l -= 1
            s.append("R")
            f = 1
        elif a[j]>x:
            x = a[0]
            s.append("L")
            f = 1
            j += 1
    if f==0:
        break
print(len(s))
print(*s,sep="")