from bisect import bisect_left as bl
from bisect import bisect_right as br
from heapq import heappush,heappop
import math
from collections import *
from functools import reduce,cmp_to_key,lru_cache
from itertools import *
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
def li3():return [int(i) for i in st()]




for _ in range(val()):
    n = val()
    l1 = li()
    l2 = li()
    
    # print(l1,l2)

    if len(l1) != len(l2) or (n&1 and l1[n//2] != l2[n//2]):
        print('NO')
        continue

    A = []
    B = []
    for i in range(n//2):
        A.append(sorted([l1[i],l1[n-i-1]]))
        B.append(sorted([l2[i],l2[n-i-1]]))
    
    print('Y' if sorted(A) == sorted(B) else 'n')


