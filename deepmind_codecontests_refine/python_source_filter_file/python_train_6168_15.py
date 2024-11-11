# cook your dish here
import math,sys
import heapq
from fractions import Fraction
from collections import Counter,defaultdict
def li(): return list(map(int,sys.stdin.readline().split()))
def ls(): return list(map(int,list(input())))
def la(): return list(input())
def ii():  return int(input())
def dic(x): return defaultdict(lambda: x) 
def isPrime(n):
    i= 2
    if n == 1:
        return False
    while i <= int(math.sqrt(n)):
        if n%i == 0:
            return False
        i = i + 1
    return True
def gcd(a,b):
    if b == 0:
        return a
    return gcd(b,a%b)
def LCM(a,b): 
    return (a*b) / gcd(a,b) 
  
t = ii()
for _ in range(t):
    n,k = li()
    s = la()
    s.sort()
    c = Counter(s)
    u = set(s)
    if k == 1:
        print(''.join(s))
    else:
        if c[s[0]] <k:
            print(s[k-1])
        else:
            if len(u) == 1:
                x =  n//k
                if (n%k != 0):
                    x = x+1
                print(x*s[0])
            elif len(u) == 2 and c[s[0]] == k:
                x =  c[s[1]]//k
                if (c[s[1]]%k != 0):
                    x = x+1
                y =s[0]+s[k]*x
                print(''.join(y))
            else:
                x = [s[0]]+s[k:n]
                print(''.join(x))
            
        
        