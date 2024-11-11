
def STR(): return list(input())
def INT(): return int(input())
def MAP(): return map(int, input().split())
def MAP2():return map(float,input().split())
def LIST(): return list(map(int, input().split()))
def STRING(): return input()
import string
import sys
from heapq import heappop , heappush
from bisect import *
from collections import deque , Counter , defaultdict
from math import *
from itertools import permutations , accumulate
dx = [-1 , 1 , 0 , 0  ]
dy = [0 , 0  , 1  , - 1]
#visited = [[False for i in range(m)] for j in range(n)]
#sys.stdin = open(r'input.txt' , 'r')
#sys.stdout = open(r'output.txt' , 'w')
#for tt in range(INT()):


#CODE

n, m = MAP()

b = LIST()
b = b[1 : ]
g = LIST()
g = g[1:]

bs = [0] * n
gs = [0] * m

if len(b) > 0 :
    for i in b :
        bs[i] = 1

if len(g) > 0 :
    for i in g :
        gs[i] = 1

for i in range(509):
    x = i % n
    y = i % m
    if bs[x] == 1 and gs[y] == 0 :
        gs[y] = 1

    elif bs[x] == 0 and gs[y] == 1:
        bs[x] = 1

c1 , c2 = 0 , 0
for i in range(n):
    if bs[i] == 1 :
        c1 +=1

for i in range(m):
    if gs[i] == 1:
        c2 +=1

if c1 == n and c2 == m :
    print('Yes')

else:
    print('No')


