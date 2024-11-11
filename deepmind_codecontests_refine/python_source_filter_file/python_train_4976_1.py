# coding: utf-8
# Your code here!

import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline 

#n = int(input())
n,m = [int(i) for i in readline().split()]

g = [[] for _ in range(n)]
for _ in range(m):
    s,t = [int(i)-1 for i in readline().split()]
    g[s].append(t)

L = [len(gi) for gi in g]

p = [0]*n
p[0] = 1
for i in range(n-1):
    c = p[i]/L[i]
    for v in g[i]:
        p[v] += c

dp0 = [0]*(n)
dp1 = [1000000]*(n)

for i in range(n-2,-1,-1):
    res = 0
    m = 0
    for v in g[i]:
        res += dp0[v]
        if m<dp0[v]: m = dp0[v]
    dp0[i] = 1 + res/L[i]

    if L[i] >= 2:
        dp1[i] = 1 + (res-m)/(L[i]-1)
    
res = max(res,(dp0[i] - dp1[i])*p[i] for i in range(n))

print(dp0[0]-max(0,res))










