from bisect import bisect_left as bl
from bisect import bisect_right as br
from heapq import heappush,heappop
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
    n = val()
    l = li()
    
    if max(l) == min(l):
        print('NO')
        continue
    
    print('YES')
    root = l[0]
    same = set()
    other = -1
    for i in range(1, n):
        if l[i] == root:
            same.add(i)
        else:
            other = i
            print(1, i + 1)
    
    for i in same:
        print(i + 1, other)