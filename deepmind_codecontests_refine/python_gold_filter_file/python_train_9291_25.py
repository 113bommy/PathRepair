from sys import stdin, setrecursionlimit, stdout
setrecursionlimit(1000000)
from collections import deque
from math import sqrt, floor, ceil, log, log2, log10, pi, gcd, sin, cos, asin
from heapq import heapify, heappop, heappush, heappushpop, heapreplace
def ii(): return int(stdin.readline())
def fi(): return float(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def fmi(): return map(float, stdin.readline().split())
def li(): return list(mi())
def si(): return stdin.readline().rstrip()
def lsi(): return list(si())
#mod=1000000007
res=['YES', 'NO']


#\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\#
#############\\\\\\\\\\\\\ CODE STARTS HERE /////////////#############
#////////////////////////////////////////////////////////////////////#




test_case=ii()
while test_case:
    test_case-=1




    n, k=mi()
    a=[0]*(n*n)
    i=0
    while k:
        a[i]=1
        i+=n+1
        k-=1
        if i>=n*n:
            i-=n*n
    ans=[]
    for j in range(n):
        ans.append([i for i in a[j*n:j*n+n]])
    r=[]
    c=[]
    for i in ans:
        r.append(sum(i))
    for i in range(n):
        s=0
        for j in range(n):
            s+=ans[j][i]
        c.append(s)
    print((max(r)-min(r))**2+((max(c))-min(c))**2)
    for i in ans:
        print(*i, sep='')