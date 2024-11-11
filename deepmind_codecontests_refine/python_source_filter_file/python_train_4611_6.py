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


n = val()
parents = [1, 1] + li()
values = [0] + li()

sizes = [1] * (n + 5)

for i in range(2, n + 1, 1):
    sizes[parents[i]] = 0
    
ans = -float('inf')

for i in range(n - 1, 0, -1):
    ans = max(ans, (values[i] + sizes[i] - 1) / sizes[i])
    values[parents[i]] += values[i]
    sizes[parents[i]] += sizes[i]
    
print(int(ans))
    