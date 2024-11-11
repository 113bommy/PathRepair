# Lets goto the next level 
# AIM Specialist at CF *__* asap 
# template taken from chaudhary_19  
# Remember you were also a novice when you started, 
# hence never be rude to anyone who wants to learn something
# Never open a ranklist untill and unless you are done with solving problems, wastes 3/4 minuts 
# Donot treat CP as a placement thing, love it and enjoy it, you will succeed for sure.  
# Any doubts or want to have a talk, contact https://www.facebook.com/chaudhary.mayank


# ///==========Libraries, Constants and Functions=============///

import sys
from bisect import bisect_left,bisect_right,insort
from collections import deque,Counter
from math import gcd,sqrt,factorial,ceil,log10,log2,floor
from itertools import permutations
from heapq import heappush,heappop,heapify
inf = float("inf")
mod = 10**9+7
#sys.setrecursionlimit(10**9)


def factorial_p(n, p):
    ans = 1
    if n <= p // 2:
        for i in range(1, n + 1):
            ans = (ans * i) % p
    else:
        for i in range(1, p - n):
            ans = (ans * i) % p
        ans = pow(ans, p - 2, p)
        if n % 2 == 0:
            ans = p - ans
    return ans


def nCr_p(n, r, p):
    ans = 1
    while (n != 0) or (r != 0):
        a, b = n % p, r % p
        if a < b:
            return 0
        ans = (ans * factorial_p(a, p) * pow(factorial_p(b, p), p - 2, p) * pow(factorial_p(a - b, p), p - 2, p)) % p
        n //= p
        r //= p
    return ans

def prime_sieve(n):
    """returns a sieve of primes >= 5 and < n"""
    flag = n % 6 == 2
    sieve = bytearray((n // 3 + flag >> 3) + 1)
    for i in range(1, int(n**0.5) // 3 + 1):
        if not (sieve[i >> 3] >> (i & 7)) & 1:
            k = (3 * i + 1) | 1
            for j in range(k * k // 3, n // 3 + flag, 2 * k):
                sieve[j >> 3] |= 1 << (j & 7)
            for j in range(k * (k - 2 * (i & 1) + 4) // 3, n // 3 + flag, 2 * k):
                sieve[j >> 3] |= 1 << (j & 7)
    return sieve
def prime_list(n):                            #<----- You have to call me if you wanna get list of primes upto range n
    """returns a list of primes <= n"""
    res = []
    if n > 1:
        res.append(2)
    if n > 2:
        res.append(3)
    if n > 4:
        sieve = prime_sieve(n + 1)
        res.extend(3 * i + 1 | 1 for i in range(1, (n + 1) // 3 + (n % 6 == 1)) if not (sieve[i >> 3] >> (i & 7)) & 1)
    return res
    
def is_prime(n):
    """returns True if n is prime else False"""
    if n < 5 or n & 1 == 0 or n % 3 == 0:
        return 2 <= n <= 3
    s = ((n - 1) & (1 - n)).bit_length() - 1
    d = n >> s
    for a in [2, 325, 9375, 28178, 450775, 9780504, 1795265022]:
        p = pow(a, d, n)
        if p == 1 or p == n - 1 or a % n == 0:
            continue
        for _ in range(s):
            p = (p * p) % n
            if p == n - 1:
                break
        else:
            return False
    return True

def all_factors(n):
    """returns a sorted list of all distinct factors of n"""
    small, large = [],[]
    for i in range(1, int(n**0.5) + 1, 2 if n & 1 else 1):
        if not n % i:
            small.append(i)
            large.append(n//i)
    large.reverse()
    small.extend(large)
    return small

def all_subsets(Arr):
    subset=[0]*n
    helper(Arr,subset,0)

def helper(Arr,subset,i):
    global flag
    if i==n:
        if sum(subset)==0 or sum(subset)%360==0:
            flag=1
            print(subset)
    else:
        subset[i]=-1*Arr[i]
        helper(Arr,subset,i+1)
        subset[i]=Arr[i]
        helper(Arr,subset,i+1)

def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def input(): return sys.stdin.readline().strip()
# ///===========MAIN=============///
n=int(input())
Arr=[]
for i in range(n):
    Arr.append(int(input()))
flag=0
all_subsets(Arr)
if flag==1:
    print("YES")
else:
    print("NO")
