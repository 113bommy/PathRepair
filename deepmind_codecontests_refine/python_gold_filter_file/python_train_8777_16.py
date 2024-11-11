from math import *
from collections import deque
from copy import deepcopy
import sys
def inp(): return sys.stdin.readline().rstrip("\r\n")  # for fast input
def multi(): return map(int, input().split())
def strmulti(): return map(str, inp().split())
def lis(): return list(map(int, inp().split()))
def lcm(a, b): return (a * b) // gcd(a, b)
def ncr(n, r): return factorial(n) // (factorial(r) * factorial(max(n - r, 1)))
def stringlis(): return list(map(str, inp().split()))
def out(var): sys.stdout.write(str(var))  # for fast output, always take string
def printlist(a):
    print(' '.join(str(a[i]) for i in range(len(a))))
def isPrime(n):
    if (n <= 1): return False
    if (n <= 3): return True
    if (n % 2 == 0 or n % 3 == 0): return False
    i = 5
    while (i * i <= n):
        if (n % i == 0 or n % (i + 2) == 0):
            return False
        i = i + 6
    return True
def google():
    t = int(inp())

    for T in range(t):
        print("Case #" + str(T + 1) + ": ", end="")
        solve()
def normal(x):
    if(x==0):
        t = int(inp())
    else:
        t=1
    for T in range(t):
        solve()

# copied functions end

# start coding

def solve():
    n,a,b=multi()
    if(b==1):
        print("YES")
        return
    if(a==1):
        if(floor((n-1)/b)==ceil((n-1)/b)):
            print("YES")
        else:
            print("NO")
        return
    i=0
    while(a**i<=n):
        if(n%b==a**i%b):
            print("YES")
            return
        i+=1
    print("NO")
    return






normal(0)









