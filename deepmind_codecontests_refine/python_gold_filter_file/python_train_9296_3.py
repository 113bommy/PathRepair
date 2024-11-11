import sys, math, itertools, random, bisect
from collections import defaultdict
INF = sys.maxsize
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def input(): return sys.stdin.readline().strip()
mod = 10**9 + 7

def check(a,m,k):
    b = [1 if i>=m else -1 for i in a]
    for i in range(1,len(b)):
        b[i] += b[i-1]
    
    ans = False
    if b[k-1]>0: ans = True
    mn = 0
    for i in range(k,len(b)):
        mn = min(mn,b[i-k])
        if b[i]-mn>0: ans = True
    return ans

for _ in range(1):
    n,k = get_ints()
    a = get_array()
    l,r = 1,n
    while l<=r:
        m = (l+r)//2
        if check(a,m,k): l = m+1
        else: r = m-1
    print(r)



