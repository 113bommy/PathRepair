from sys import *
from math import *
t=int(stdin.readline())
for _ in range(t):
    n=int(stdin.readline())
    a = list(map(int, stdin.readline().split()))
    a.sort()
    b=[a[n-1]]
    x=a[0]
    a.pop(0)
    while a:
        y = 0
        i=0
        for j in range(len(a)):
            m=gcd(x,a[j])
            if m>y:
                i=j
                y=m
        x=y
        b.append(a[i])
        a.pop(i)
    print(*b)
