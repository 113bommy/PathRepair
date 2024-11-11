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

def primes(n):
    """ Returns  a list of primes < n """
    sieve = [True] * n
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return [2] + [i for i in range(3,n,2) if sieve[i]]

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

s = input().decode('utf-8').strip()
# n = int(input())
# l = list(map(int, input().split()))
c = Counter(s)
dp = [0] * len(s)

primes = primes(len(s))
components = []
for p in primes:
    l = []
    for i in range(p, len(s)+1, p):
        l.append(i)
    for comp in components:
        if len(list(set(comp) & set(l))):
            comp += l
            break
    else:
        if len(l):
            components.append(l)

need = []
for comp in components:
    need.append(len(set(comp)))

import heapq
heap = []
for e, v in c.items():
    heapq.heappush(heap, (-v, e))

result = [""] * (len(s))
for comp in components:
    i, letter = heapq.heappop(heap)
    i = -i


    indexes = set(comp)
    if i >= len(indexes):
        heapq.heappush(heap, (-(i-len(indexes)), letter))
        for index in set(comp):
            result[index-1] = letter
    else:
        print("NO")
        break
else:
    while len(heap):
        i, letter = heapq.heappop(heap)
        for j in range(len(result)):
            if i == 0:
                break
            if result[j] == "":
                result[j] = letter
                i -= 1
    print("YES")
    print("".join(result))
# a = sorted(list(c.values()))
# b = sorted(need)
#
# i, j = len(b)-1, len(a)-1
# while i >= 0 and j >= 0:
#     if b[i] <= a[j]:
#         a[j] -= b[i]
#         i -= 1
#     else:
#         j -= 1
#
# if i == -1:
#     print("YES")
# else:
#     print("NO")
