import math,sys
from sys import stdin,stdout
from collections import Counter, defaultdict, deque
input = stdin.readline
I = lambda:int(input())
li = lambda:list(map(int,input().split()))

def solve():
    a,b=li()
    if(a*2>b):
        print('YES')
    else:
        print("NO")
for _ in range(I()):
    solve()