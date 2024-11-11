MOD = 1000000007
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
from math import *
a,b,c,d=f()
if (a/c)<(b/d):
    x=a*b*c*c-a*a*c*d
    y=a*b*c*c
    g=gcd(x, y)
    print(str(x//g)+'/'+str(y//g))
elif (a/c)>(b/d):
    x=a*b*d*d-c*b*d*b
    y=a*b*d*d
    g = gcd(x, y)
    print(str(x // g) + '/' + str(y // g))
else:
    print(0)