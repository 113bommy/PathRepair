from bisect import bisect_left as bl
from bisect import bisect_right as br
from heapq import heappush,heappop
import math
from collections import *
from functools import reduce,cmp_to_key,lru_cache
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
# import sys
# input = sys.stdin.readline

M = mod = 10**9 + 7 
def factors(n):return sorted(set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))
def inv_mod(n):return pow(n, mod - 2, mod)

def li():return [int(i) for i in input().rstrip().split()]
def st():return str(input().rstrip())[2:-1]
def val():return int(input().rstrip())
def li2():return [str(i)[2:-1] for i in input().rstrip().split()]
def li3():return [int(str(i)[2:-1]) for i in input().rstrip()]


for _ in range(val()):
    n,k = li()

    for j in range(k):
        last = n
        n = n + min([int(i) for i in str(n)])*max([int(i) for i in str(n)])
        if n == last:break
    print(n)