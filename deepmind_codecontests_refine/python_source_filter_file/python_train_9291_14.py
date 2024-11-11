from bisect import bisect_left as bl
from bisect import bisect_right as br
from heapq import heappush,heappop,heapify
import math
from collections import *
from functools import reduce,cmp_to_key
import sys
input = sys.stdin.readline
M = mod = 998244353
def factors(n):return sorted(set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))
def inv_mod(n):return pow(n, mod - 2, mod)
 
def li():return [int(i) for i in input().rstrip('\n').split()]
def st():return input().rstrip('\n')
def val():return int(input().rstrip('\n'))
def li2():return [i for i in input().rstrip('\n')]
def li3():return [int(i) for i in input().rstrip('\n')]



for _ in range(val()):
    n, k = li()
    l = [[0 for i in range(n)] for j in range(n)]
    he1 = []
    he2 = []
    rows = [0]*n
    cols = [0]*n
    for i in range(n):
        heappush(he1,[0,i])
        heappush(he2,[0,i])
    while k:
        k -= 1
        su1,i = heappop(he1)
        su2,j = heappop(he2)
        rows[i] += 1
        cols[j] += 1
        heappush(he1,[su1 + 1,i])
        heappush(he2,[su2 + 1,j])
        # print(he1)
    # print(rows)
    # print(cols)
    for i in range(n):
        he2[i][0] *= -1
    heapify(he2)
    he3 =[]
    ans = (max(rows) - min(rows))**2 + (max(cols) - min(cols))**2
    # print(he2)
    for i in range(n):
        he3 = []
        while rows[i]:
            rows[i] -= 1
            su,j = heappop(he2)
            su += 1
            l[i][j] = 1
            if su:heappush(he3,[su,j])
        
        he2.extend(he3)
        heapify(he2)
        print(he2)

    
    print(ans)
    for i in l:print(*i,sep = '')