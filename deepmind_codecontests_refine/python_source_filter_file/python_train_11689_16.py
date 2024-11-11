# Coder : Hakesh D #
import sys
#input=sys.stdin.readline

from collections import deque
from math import ceil,sqrt,gcd,factorial
from bisect import bisect_right,bisect_left

mod = 1000000007
INF = 10**18
NINF = -INF
def INT():return int(input())
def MAP():return map(int,input().split())
def LIST():return list(map(int,input(),split()))
def modi(x):return pow(x,mod-2,mod)
def lcm(x,y):return (x*y)//gcd(x,y)
def write(l):
    for i in l:
        print(i,end=' ') 
    print()
########################################################################################
n = int(input())
r,s,p=MAP()
rr,ss,pp=MAP()
maxa = min(r,ss) + min(s,pp) + min(p,rr)
mini = min(r,rr+ss) + min(s,ss + pp) + min(p,pp + rr)

print(n - mini,maxa)