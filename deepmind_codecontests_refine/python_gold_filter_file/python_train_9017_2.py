import sys,os,io
import math,bisect,operator
inf,mod = float('inf'),10**9+7
# sys.setrecursionlimit(10 ** 6)
from itertools import groupby,accumulate
from heapq import heapify,heappop,heappush
from collections import deque,Counter,defaultdict
I = lambda : int(sys.stdin.buffer.readline())
Neo = lambda : list(map(int, sys.stdin.buffer.readline().split()))
s = input()
d = defaultdict(int)
i,j = 0,0
d[(0,0)] = 1
for c in s:
    x,y = i,j
    if c == 'L':
        j -= 1
    elif c == 'R':
        j += 1
    elif c == 'U':
        i -= 1
    else:
        i += 1   
    A = [(i-1,j),(i+1,j),(i,j-1),(i,j+1),(i,j)]
    for p,q in A:
        if (p,q) in d and (p,q) != (x,y):
            print('BUG')
            exit()
    d[(i,j)] = 1    
print('OK')                     
