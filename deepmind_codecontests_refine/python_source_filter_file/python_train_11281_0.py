import os,io
from sys import stdout
import collections
# import random
import math
from operator import itemgetter
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from collections import Counter
# from decimal import Decimal
# import heapq
# from functools import lru_cache

# import sys
# sys.setrecursionlimit(10**6)

# from functools import lru_cache
# @lru_cache(maxsize=None)

def primes(n):
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

def kadane(a,size):
    max_so_far = 0
    max_ending_here = 0

    for i in range(0, size):
        max_ending_here = max_ending_here + a[i]
        if (max_so_far < max_ending_here):
            max_so_far = max_ending_here

        if max_ending_here < 0:
            max_ending_here = 0
    return max_so_far

# @lru_cache(maxsize=None)
def digitsSum(n):
    if n == 0:
        return 0
    r = 0
    while n > 0:
        r += n % 10
        n //= 10
    return r

def print_grid(grid):
    for line in grid:
        print("".join(line))

# INPUTS  --------------------------
# s = input().decode('utf-8').strip()
# n = int(input())
# l = list(map(int, input().split()))
# t = int(input())
# for _ in range(t):
# for _ in range(t):

t = int(input())
for _ in range(t):
    n = int(input())
    boxes = []
    i = 0
    for _ in range(2*n-1):
        boxes.append(list(map(int, input().split()))+[i+1])
        i+=1
    boxes = sorted(boxes, key=itemgetter(1))

    even = boxes[::2]
    odd = boxes[1::2] + [boxes[-1]]

    apples = sum([e[1] for e in boxes])
    halfapple = apples // 2
    if apples % 2 == 1:
        halfapple += 1

    aeven = sum([e[1] for e in even])
    aodd = sum([e[1] for e in odd])

    if aeven >= halfapple:
        print('YES')
        res = []
        for e in even:
            res.append(e[2])
        print(" ".join([str(e) for e in sorted(res)]))
    elif aodd >= halfapple:
        print('YES')
        res = []
        for e in odd:
            res.append(e[2])

        print(" ".join([str(e) for e in sorted(res)]))
    else:
        print('NO')
