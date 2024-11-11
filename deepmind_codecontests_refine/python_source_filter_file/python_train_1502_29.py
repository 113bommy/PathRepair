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
S = input()
b,s,c = Neo()
pb,ps,pc = Neo()
amt, = Neo()
l,r = 0,10**12
def check(m):
    x = max(0,m*S.count('B')-b)
    y = max(0,m*S.count('S')-s)
    z = max(0,m*S.count('C')-c)
    # print(m,x,y,z,x*pb+y*ps+z*pc)
    if amt >= x*pb+y*ps+z*pc:
        return 1
    return 0
for i in range(100):
    m = (l+r)//2
    # print(m,check(m))
    if check(m):
        l = m
    else:
        r = m
print(m)       
        