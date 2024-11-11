
def STR(): return list(input())
def INT(): return int(input())
def MAP(): return map(int, input().split())
def MAP2():return map(float,input().split())
def LIST(): return list(map(int, input().split()))
def STRING(): return input()
from heapq import heappop , heappush
from bisect import *
from collections import deque , Counter
from math import *
from itertools import permutations
dx = [-1 , 1 , 0 , 0  ]
dy = [0 , 0  , 1  , - 1]
#visited = [[False for i in range(m)] for j in range(n)]
#for tt in range(INT()):

n = INT()
d = set()
for i in range(1, 100009):
    j = (i*(i+1))//2
    d.add(j)

f = 0
for i in d :
    z = n - i
    if z in d :
        f = 1
        print(i , z)
        break

if f :
    print('YES')
else:
    print('NO')


