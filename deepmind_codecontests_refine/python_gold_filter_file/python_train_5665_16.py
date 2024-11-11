import sys,math,bisect
inf = float('inf')
mod = 998244353
"========================================"
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
def primeFactors(n):
    factors = []
    while n % 2 == 0:
        factors.append(2)
        n = n // 2
    for i in range(3,int(math.sqrt(n))+1,2):
        while n % i== 0:
            factors.append(i)
            n = n // i
    if n > 2:
        factors.append(n)
    return factors
"========================================="
"""
n = int(input())
n,k = map(int,input().split())
arr = list(map(int,input().split()))
"""

from collections import deque,defaultdict,Counter
import heapq


for _ in range(1):
    n=int(input())
    upper = []
    lower = []
    for i in range(n):
        i=list(map(int,input().split()))
        upper.append(i[0])
        lower.append(i[1])
    sumup  = sum(upper)
    sumlow = sum(lower)
    if sumup%2==0 and sumlow%2==0:
        print(0)
    else:

        cnt=0
        flag=False
        for i in range(n):
            if upper[i]%2!=lower[i]%2:
                sumup-=upper[i]
                sumup+=lower[i]
                sumlow-=lower[i]
                sumlow+=upper[i]
                upper[i],lower[i]=lower[i],upper[i]
                cnt+=1
                if sumup%2==0 and sumlow%2==0:
                    flag=True
                    break
        if n==1:
            if upper[0]%2==1 or lower[0]%2==1:
                print(-1)
            else:
                print(0)
        elif not flag:
            print(-1)
        else:
            print(cnt)
