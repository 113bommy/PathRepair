
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




n , a = MAP()
l1 = LIST()
r1 = 0
for i in l1:
    r1 += i* a **(n - 1)
    n-=1

m , b = MAP()
l2 = LIST()
r2 = 0
for i in l2:
    r2 += i * b ** (m - 1)
    m -= 1

#print(r1)
#print(r2)

if r1 > r2 :
    print('>')
elif r1 < r2 :
    print('<')
else:
    print('=')



