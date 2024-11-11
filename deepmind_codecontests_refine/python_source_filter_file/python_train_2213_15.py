import os,io
from sys import stdout
import collections
# import random
# import math
# from operator import itemgetter
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
# from collections import Counter
# from decimal import Decimal
# import heapq
# from functools import lru_cache

import sys
# import threading
# sys.setrecursionlimit(10**6)
# threading.stack_size(102400000)

# from functools import lru_cache
# @lru_cache(maxsize=None)

######################
# --- Maths Fns  --- #
######################
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

def distance(xa, ya, xb, yb):
    return ((ya-yb)**2 + (xa-xb)**2)**(0.5)

# @lru_cache(maxsize=None)
def digitsSum(n):
    if n == 0:
        return 0
    r = 0
    while n > 0:
        r += n % 10
        n //= 10
    return r

######################
# ---- GRID Fns ---- #
######################
def isValid(i, j, n, m):
    return i >= 0 and i < n and j >= 0 and j < m

def print_grid(grid):
    for line in grid:
        print(" ".join(map(str,line)))

######################
# ---- MISC Fns ---- #
######################
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

def prefixSum(arr):
    for i in range(1, len(arr)):
        arr[i] = arr[i] + arr[i-1]
    return arr

def ceil(n, d):
    if n % d == 0:
        return n // d
    else:
        return (n // d) + 1

def _abs(a, b):
    return int(abs(a - b))

def evenodd(l):
    even = [e for e in l if e & 1 == 0]
    odd = [e for e in l if e & 1]
    return (even, odd)

# INPUTS  --------------------------
# s = input().decode('utf-8').strip()
# n = int(input())
# l = list(map(int, input().split()))
# t = int(input())
# for _ in range(t):
from collections import Counter
n, m = list(map(int, input().split()))
x, k, y = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))

cx = x/k
cy = y
betterKillRange = cx <= cy

import math

if len(b) > len(a):
    print(-1)
    exit()
if len(b) == len(a):
    if a == b:
        print(0)
    else:
        print(-1)
    exit()

i, j = 0, 0
index = 0
result = 0
while i < len(a):

    if index >= len(b):
        j = len(a)
    else:
        while j < len(a) and a[j] != b[index]:
            j += 1


    if j != i:
        radd = 0
        elementsToDelete = j-i
        if elementsToDelete % k == 0:
            radd = x*(elementsToDelete//k)
        elif elementsToDelete > k:
            radd = (elementsToDelete // k) * x + (elementsToDelete % k) * y
        elif elementsToDelete < k:
            if i == 0 and j == len(a):
                print(-1)
                exit()
            elif i == 0:
                if max(a[i:j]) > a[j]:
                    print(-1)
                    exit()
                radd = y * elementsToDelete
            elif j == len(a):
                if max(a[i:j]) > a[i-1]:
                    print(-1)
                    exit()
                radd = y * elementsToDelete
            else:
                if max(a[i:j]) > max(a[i-1], a[j]):
                    print(-1)
                    exit()
                radd =  y * elementsToDelete

        # Try now without range
        radd2 = 0
        if i == 0 and j == len(a):
            radd2 = math.inf
        elif i == 0:
            if max(a[i:j]) > a[j]:
                if elementsToDelete < k:
                    radd2 = math.inf
                else:
                    remaining = elementsToDelete - k
                    radd2 = x
                    radd2 += remaining * y
            else:
                radd2 = y * elementsToDelete
        elif j == len(a):
            if max(a[i:j]) > a[i-1]:
                if elementsToDelete < k:
                    radd2 = math.inf
                else:
                    remaining = elementsToDelete - k
                    radd2 = x
                    radd2 += remaining * y
            else:
                radd2 = y * elementsToDelete
        else:
            if max(a[i:j]) > max(a[i-1], a[j]):
                if elementsToDelete < k:
                    radd2 = math.inf
                else:
                    remaining = elementsToDelete - k
                    radd2 = x
                    radd2 += remaining * y
            else:
                radd2 =  y * elementsToDelete

        print(radd, radd2)
        result += min(radd, radd2)
    i = j+1
    j += 1
    index += 1

print(result)
