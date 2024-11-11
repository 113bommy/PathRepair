#!/mnt/c/Users/moiki/bash/env/bin/python
import sys
sys.setrecursionlimit(10000000)
N = int(input())
from collections import defaultdict
MOD = 10**9 + 7

# T = defaultdict(list)
T = [set() for _ in range(N+1)]
for i in range(N-1):
    x,y = map(int, input().split())
    # T[x] += [y]
    # T[y] += [x]
    T[x].add(y)
    T[y].add(x)

def dfs(n,oya):
    b,w = 1,1
    for child_n in T[n]:
        if child_n == oya:
            continue
        child_b, child_w = dfs(child_n, n)
        b *= child_w % MOD
        w *= (child_b+child_w)%MOD
    return b%MOD, w%MOD
print( sum(dfs(1,None)) % MOD) 

