import sys,os,io
import math,bisect,operator
inf,mod = float('inf'),10**9+7
# sys.setrecursionlimit(10 ** 6)
from itertools import groupby,accumulate
from heapq import heapify,heappop,heappush
from collections import deque,Counter,defaultdict
input = iter(sys.stdin.buffer.read().decode().splitlines()).__next__
Neo = lambda : list(map(int,input().split()))
# test, = Neo()
n,d,h = Neo()
f = 0
Ans = []
for i in range(1,h+1):
    if i+1 > n:
        f = 1
    Ans.append((i,i+1))
t = d-h
# print(t)
if d < h or h < d-h:
    f = 1
k = h+1    
if t > 0:
    Ans.append((1,h+2))
    t -= 1   
    k += 1  
while t > 0:
    if k+1 > n:
        f = 1
    Ans.append((k,k+1)) 
    k += 1
    t -= 1
# print(k) 
if d-h == 0:
    l = 0
    for i in range(k+1,n+1):
        l = 1
        Ans.append((2,i))
    if (d < 2 or h < 2) and l:
        f = 1
else:    
    for i in range(k+1,n+1):
        Ans.append((1,i))
if len(Ans) > n-1:
    f = 1
if f:
    print(-1)
else:
    for i,j in Ans:
        print(i,j)
    