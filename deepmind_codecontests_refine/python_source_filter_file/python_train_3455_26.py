
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

n , k = MAP()
s = STR()

if k == 0 :
    print(s)
    exit(0)

if k == n == 1 :
    print('0')
    exit(0)
    
if int(s[0]) > 1 :
    s[0] = '1'
    k-=1

for i in range(1 , n):
    if k > 0 :
        if int(s[i]) > 0 :
            s[i] = '0'
            k-=1
    else:
        break

print(''.join(s))


