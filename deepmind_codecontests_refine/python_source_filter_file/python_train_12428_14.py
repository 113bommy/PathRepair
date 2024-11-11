from collections import deque
from math import ceil,floor,sqrt,gcd
def ii(): return int(input())
def mi(): return map(int,input().split())
def li(): return list(mi())
def si():return input()
s=0
n=ii()
a=li()
a.sort()
for i in range(1,n+1):
    s+=(i-a[i-1])
print(s)