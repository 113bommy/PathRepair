import sys,math,bisect

inf = float('inf')
mod = (10**9)+7

"=========================="
def lcm(a,b):
    return int((a/math.gcd(a,b))*b)
def gcd(a,b):
    return int(math.gcd(a,b))
def tobinary(n):
    return bin(n)[2:]
def binarySearch(a,x):
    i = bisect.bisect_left(a,x)
    if i!=len(a) and a[i]==x:
        return i
    else:
        return -1
def lowerBound(a, x):
    i = bisect.bisect_left(a, x)
    if i:
        return (i-1)
    else:
        return -1
def upperBound(a,x):
    i = bisect.bisect_right(a,x)
    if i!= len(a)+1 and a[i-1]==x:
        return (i-1)
    else:
        return -1
def primesInRange(n):
    ans = []
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1
    for p in range(2, n+1):
        if prime[p]:
            ans.append(p)
    return ans
"============================"
"""
n = int(input())
n,k = map(int,input().split())
arr = list(map(int,input().split()))
"""
from collections import deque,defaultdict,Counter
import heapq
for _ in range(1):
    s=input()
    t=input()
    sa=sorted(s)
    ta=sorted(t)
    def subset(t,s):
        i=0
        for x in s:
            if x==t[i]:
                i+=1
            if i==len(t):
                break
        return i==len(t)
    if sa==ta:
        print('array')
    elif subset(t,s):
        print('automaton')
    elif subset(ta,sa):
        print('both')
    else:
        print('need tree')
