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
    
def DFS(n,s,adj):              
    visited = [False for i in range(n+1)]  
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
                
def condition_satisfied(ans,position,arr,pos,wrong_num,right_num,i):
    ans.append((i+1,pos+1))
    position[wrong_num] = pos
    position[right_num] = i
    arr[pos],arr[i] = wrong_num,right_num
    return ans,arr,position
        
def solve():
    n = int(input())
    arr = list_input()
    position = {}
    ans = []
    for i in range(n):
        position[arr[i]] = i
    
    for i in range(n):
        if arr[i] == i+1:
            continue
        pos = position[i+1]
        wrong_num,right_num = arr[i],i+1
        if abs(i-pos) >= n//2:
            ans,arr,position = condition_satisfied(ans,position,arr,pos,wrong_num,right_num,i)
        else:
            if abs(n-pos-1) >= n//2:
                ans.append((n,pos+1))
                position[right_num],position[arr[-1]] = n-1,pos
                arr[pos],arr[-1] = arr[-1],arr[pos]
                pos = n-1
                if abs(i-pos) >= n//2:
                    ans,arr,position = condition_satisfied(ans,position,arr,pos,wrong_num,right_num,i)
                else:
                    ans.append((1,n))
                    position[right_num],position[arr[0]] = 0,pos
                    arr[0],arr[-1] = arr[-1],arr[0]
                    pos = 0
                    ans,arr,position = condition_satisfied(ans,position,arr,pos,wrong_num,right_num,i)
            else:
                ans.append((1,pos+1))
                position[right_num],position[arr[0]] = 0,pos
                arr[0],arr[pos] = arr[pos],arr[0]
                pos = 0
                if abs(i-pos) >= n//2:
                    ans,arr,position = condition_satisfied(ans,position,arr,pos,wrong_num,right_num,i)
                else:
                    ans.append((1,n))
                    position[right_num],position[arr[-1]] = n-1,pos
                    arr[0],arr[-1] = arr[-1],arr[0]
                    pos = n-1
                    ans,arr,position = condition_satisfied(ans,position,arr,pos,wrong_num,right_num,i)
    print(len(ans))
    #print(*arr)
    for u,v in ans:
        print(u,v)

t = 1
#t = int(input())
for _ in range(t):
    solve()


    
    
    
    
