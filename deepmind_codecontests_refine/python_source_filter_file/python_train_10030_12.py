import math, re, sys, string, operator, functools, fractions, collections
sys.setrecursionlimit(10**7)
RI=lambda x=' ': list(map(int,input().split(x)))
RS=lambda x=' ': input().rstrip().split(x)
dX= [-1, 1, 0, 0,-1, 1,-1, 1]
dY= [ 0, 0,-1, 1, 1,-1,-1, 1]
mod=int(1e9+7)
eps=1e-6
pi=math.acos(-1.0)
MAX=100
#################################################
a,b,r=RI()
print(["First","Second"][max(a,b)<2*r])


