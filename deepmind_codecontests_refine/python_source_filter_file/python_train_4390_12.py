import bisect
import decimal
from decimal import Decimal
import os
from collections import Counter
import bisect
from collections import defaultdict
import math
import random
import heapq 
from math import sqrt
import sys
from functools import reduce, cmp_to_key
from collections import deque
import threading
from itertools import combinations
from io import BytesIO, IOBase
from itertools import accumulate

# sys.setrecursionlimit(200000)
# mod = 10**9+7
# mod = 998244353
decimal.getcontext().prec = 46

def primeFactors(n): 
    prime = {}
    while n % 2 == 0: 
        try:
            prime[2] += 1
        except KeyError:
            prime[2] = 1
        n = n//2
    for i in range(3,int(math.sqrt(n))+1,2): 
        while n % i== 0: 
            try:
                prime[i] += 1
            except KeyError:
                prime[i] = 1
            n = n//i 
    if n > 2: 
        try:
            prime[n] += 1
        except KeyError:
            prime[n] = 1
    return list(prime.values())
    
def getFactors(n) : 
    factors = 0
    i = 2
    while i <= math.sqrt(n): 
        if (n % i == 0) : 
            if (n // i == i) : 
                factors += 1
            else : 
                factors += 2
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
    
def DFS(n,s,adj):              
    visited = [False for i in range(n)]  
    stack = [] 
    stack.append(s)  
  
    while (len(stack)):  
        s = stack[-1]  
        stack.pop() 
  
        if (not visited[s]):  
            visited[s] = True 
 
        for node in adj[s]:  
            if (not visited[node]):  
                stack.append(node) 
                
def isPrime(n) : 
    if (n <= 1) : 
        return False
    if (n <= 3) : 
        return True
    if (n % 2 == 0 or n % 3 == 0) : 
        return False
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return False
        i = i + 6
    return True
        
def solve():
    n = int(input())
    arr = list_input()
    if n == 1:
        if isPrime(arr[0]):
            print(arr[0]**2)
        else:
            print(-1)
        return
    arr.sort()
    start,end = 1,n-2
    ans = arr[0]*arr[-1]
    while start <= end:
        temp = arr[start]*arr[end]
        if temp != ans:
            print(-1)
            return
        start += 1
        end -= 1
    primes = primeFactors(ans)
    temp = 0
    for i in primes:
        temp += (i+1)
    temp -= 2
    if temp == n:
        print(ans)
        return
    print(-1)

t = 1
t = int(input())
for _ in range(t):
    solve()


    
    
    
    
