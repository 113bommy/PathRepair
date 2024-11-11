from bisect import bisect_left as bl
from bisect import bisect_right as br
from heapq import heappush,heappop
import math
from collections import *
from functools import reduce,cmp_to_key
# import io, os
# input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
import sys
input = sys.stdin.readline

M = mod = 998244353
def factors(n):return sorted(set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))
def inv_mod(n):return pow(n, mod - 2, mod)

def li():return [int(i) for i in input().split()]
def st():return input()
def val():return int(input().rstrip('\n'))
def li2():return [i for i in input()]
def li3():return [int(i) for i in input()]


for _ in range(val()):
    n,k = li()
    l = li()
    cnt = Counter()
    mins = []
    maxs = []
    sums = []
    arr = [0]*(2*k + 5)
    for i in range(n//2):
        cnt[l[i] + l[n-i-1]] += 1
        a,b = max(l[i],l[n-i-1]),min(l[i],l[n-i-1])


        arr[b] += 1
        arr[a + k] -= 1


        maxs.append(a + k - b)
        mins.append(b + 1)

    mins.sort()
    maxs.sort()

    ans = n
    curr = arr[1]
    for i in range(2,2*k + 1,1):
        onecost = curr - cnt[i]
        twocost =  n//2 - curr
        ans = min(ans,onecost + twocost*2)
        curr += arr[i]
    print(ans)
