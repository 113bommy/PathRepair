from sys import stdin
from collections import deque
from math import sqrt, floor, ceil, log, log2, log10, pi, gcd, sin, cos, asin
def ii(): return int(stdin.readline())
def fi(): return float(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def fmi(): return map(float, stdin.readline().split())
def li(): return list(mi())
def lsi():
    x=list(stdin.readline())
    x.pop()
    return x
def si(): return stdin.readline()
res=['YES', 'NO']
############# CODE STARTS HERE #############
for _ in range(ii()):
    n=ii()
    f=1
    a=li()
    for i in range(1, n):
        if a[i]!=a[i-1]:
            f=0
            break
    if f:
        print(1)
        print(*[1]*n)
    else:
        f=2
        s=[1, 2]*(n//2)
        if n%2:
            if a[-1]==a[0]:
                s.append(1)
            else:
                s.append(2)
                f=3
                for i in range(n-2, -1, -1):
                    if a[i]==a[-1]:
                        f=2
                        break
                    if s[i-1]==2:
                        s[i]=1
                    else:
                        s[i]=2
                if f==3:
                    s[0]=3
        print(f)
        print(*s)