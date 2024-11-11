from math import *
a,b = map(int,input().split())
n = log(b/a)/log(3/2)
if n == ceil(n):
    print(n+1)
else:
    print(ceil(n))