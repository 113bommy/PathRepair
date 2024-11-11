import os,io
from sys import stdout
import collections
import random
import math
from operator import itemgetter
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from collections import Counter

# import sys
# sys.setrecursionlimit(10**6)

def binomial_coefficient(n, k):
    if 0 <= k <= n:
        ntok = 1
        ktok = 1
        for t in range(1, min(k, n - k) + 1):
            ntok *= n
            ktok *= t
            n -= 1
        return ntok // ktok
    else:
        return 0

def powerOfK(k, max):
    if k == 1:
        return [1]
    if k == -1:
        return [-1, 1]

    result = []
    n = 1
    while n <= max:
        result.append(n)
        n *= k
    return result

def prefixSum(arr):
    for i in range(1, len(arr)):
        arr[i] = arr[i] + arr[i-1]
    return arr

def divisors(n):
    i = 1
    result = []
    while i*i <= n:
        if n%i == 0:
            if n/i == i:
                result.append(i)
            else:
                result.append(i)
                result.append(n/i)
        i+=1
    return result

# from functools import lru_cache
# @lru_cache(maxsize=None)


n = int(input())
l = list(map(int, input().split()))

rs = Counter(l)
ls = collections.defaultdict(int)

left = prefixSum(l[:])
right = prefixSum(l[::-1])[::-1]

found = False
for i in range(0, n-1):
    #print(rs, ls, l[i])
    rs[l[i]] -= 1
    ls[l[i]] += 1
    #print(left[i], right[i]-l[i])

    if left[i] == right[i] - l[i]:
        found = True
        print("YES")
        break

    if left[i] > right[i] - l[i]:
        diff = left[i] - (right[i] - l[i])
        if diff % 2 != 0:
            continue
        if diff // 2 in ls and ls[diff//2] > 0:
            found = True
            print("YES")
            break
    else:
        diff = (right[i] - l[i]) - left[i]
        if diff % 2 != 0:
            continue
        if diff // 2 in rs and rs[diff//2] > 0:
            found = True
            print("YES")
            break

if not found:
    print("NO")
