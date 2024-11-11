# Coder : Hakesh D #
import sys
#input=sys.stdin.readline

from collections import deque
from math import ceil,sqrt,gcd,factorial
from bisect import bisect_right,bisect_left

mod = 998244353
INF = 10**18
NINF = -INF
def I():return int(input())
def MAP():return map(int,input().split())
def LIST():return list(map(int,input().split()))
def modi(x):return pow(x,mod-2,mod)
def lcm(x,y):return (x*y)//gcd(x,y)
def write(l):
    for i in l:
        print(i,end=' ') 
    print()
########################################################################################
arr = [0,1]
for i in range(200002):
    arr.append((arr[-1]+arr[-2])%mod)



n = int(input())
iden = modi(pow(2,n,mod))
ans = (arr[n]*iden)%mod
print(arr[n],pow(2,n))
print(ans)
