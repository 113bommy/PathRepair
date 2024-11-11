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
############# CODE STARTS HERE #############
n, m=mi()
a=li()
s=sum(a)
for i in range(n):
    if a[i]+m-i-1==n:
        print(-1)
        exit()
if s<n:
    print(-1)
    exit()
ans=[]
x=1
for i in range(m):
    ans.append(x)
    n-=1
    x+=1
    s-=a[i]
    if n>s:
        x+=n-s
        n=s
print(*ans)