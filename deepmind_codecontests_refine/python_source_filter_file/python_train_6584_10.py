# -*- coding: utf-8 -*-
import math, string, itertools, fractions, heapq, collections, re, array, bisect, sys, functools
def solve(line):
    n,k=map(int,line.split())
#print(n,k)
    if n<=k: return 1
    ans=n
    for i in range(2,int(math.sqrt(n))+1):
        if n%i==0: ans=min(ans, i if n/i<=k else n, n/i if i<=k else n)
    return ans
    
T = int(sys.stdin.readline())
t = 0
while True:
    line = sys.stdin.readline().rstrip()
    if not line:
        break
    print(solve(line))
    t += 1
