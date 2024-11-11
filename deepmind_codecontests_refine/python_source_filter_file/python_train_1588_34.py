import bisect
import os
from collections import Counter
import bisect
from collections import defaultdict
import math
import random
import heapq as hq
from math import tan
import sys
from functools import reduce, cmp_to_key
from collections import deque
import threading
from itertools import combinations
from io import BytesIO, IOBase
from itertools import accumulate

# sys.setrecursionlimit(200000)
# mod = 10**9+7
# mod = 987

def primeFactors(n): 
    prime = set()
    while n % 2 == 0: 
        prime.add(2)
        n = n//2
    for i in range(3,int(math.sqrt(n))+1,2): 
        while n % i== 0: 
            prime.add(i)
            n = n//i 
    if n > 2: 
        prime.add(n)
    return list(prime)
    
def getFactors(n) : 
    factors = []
    i = 1
    while i <= math.sqrt(n): 
        if (n % i == 0) : 
            if (n // i == i) : 
                factors.append(i)
            else : 
                factors.append(i)
                factors.append(n//i)
        i = i + 1
    return factors
    
def SieveOfEratosthenes(n): 
    prime = [True for i in range(n+1)] 
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p * p, n+1, p): 
                prime[i] = False
        p += 1
    num = []
    for p in range(2, n+1): 
        if prime[p]: 
            num.append(p)
    return num

def lcm(a,b):
    return (a*b)//math.gcd(a,b)

def sort_dict(key_value):
    return sorted(key_value.items(), key = lambda kv:(kv[1], kv[0]))

def list_input():
    return list(map(int,input().split()))
    
def num_input():
    return map(int,input().split())
    
def string_list():
    return list(input())
    
def decimalToBinary(n):  
    return bin(n).replace("0b", "")  
    
def binaryToDecimal(n): 
    return int(n,2) 
    
def polyapothem(n):
    a = 1
    return a / (2 * tan((180 / n) * 3.14159 / 180)) 
        
def solve():
    n = int(input())
    print(2*polyapothem(2*n))

t = int(input())
#t = 1
for _ in range(t):
    solve()


    
    
    
    
