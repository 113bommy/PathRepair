from collections import defaultdict, deque, Counter
from sys import stdin, stdout
from heapq import heappush, heappop
import math
import io
import os
import math
import bisect

#?############################################################


def isPrime(x):
    for i in range(2, x):
        if i*i > x:
            break
        if (x % i == 0):
            return False
    return True

#?############################################################


def ncr(n, r, p):
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den, p - 2, p)) % p


#?############################################################

def primeFactors(n):
    l = []
    while n % 2 == 0:
        l.append(2)
        n = n / 2
    for i in range(3, int(math.sqrt(n))+1, 2):
        while n % i == 0:
            l.append(int(i))
            n = n / i
    if n > 2:
        l.append(n)
    return list(set(l))


#?############################################################

def power(x, y, p):
    res = 1
    x = x % p
    if (x == 0):
        return 0
    while (y > 0):
        if ((y & 1) == 1):
            res = (res * x) % p
        y = y >> 1
        x = (x * x) % p
    return res

#?############################################################


def sieve(n):
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1
    return prime


#?############################################################

def digits(n):
    c = 0
    while (n > 0):
        n //= 10
        c += 1
    return c

#?############################################################


def ceil(n, x):
    if (n % x == 0):
        return n//x
    return n//x+1

#?############################################################


def mapin():
    return [int(x) for x in input().split()]

#?############################################################


input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
# python3 15.py<in>op

t = int(input())
for _ in range(t):
    
    n = int(input())
    ll  = mapin()
    fl = -1
    for i in range(n-1):
        if(ll[i] == 0 and ll[i+1] == 1):
            fl = i+1
            break
        
    if(ll[0] == 1):
        fl = 1
        
    if(ll[-1] == 0):
        fl = n
        
    if(fl == -1):
        print(fl)
        
        
    else:
        l =[]
        for i in range(fl):
            l.append(i+1) 
            
        l.append(n+1)
        for i in range(n-fl):
            l.append(fl+i+1)
            
            
        print(*l)   