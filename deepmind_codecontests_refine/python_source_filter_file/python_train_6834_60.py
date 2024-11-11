from collections import deque
from math import ceil,floor,sqrt,gcd
def ii(): return int(input())
def mi(): return map(int,input().split())
def li(): return list(mi())
def si():return input()
n=ii()
if(n>34):
    print('-1')
else:
    x=n//2
    y=n%2
    print('8'*x+'6'*y)
    