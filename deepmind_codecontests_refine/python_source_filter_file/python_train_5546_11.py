from sys import stdin, stdout
from math import floor, gcd, fabs, factorial, fmod, sqrt, inf, log
from collections import defaultdict as dd, deque
from heapq import merge, heapify, heappop, heappush, nsmallest
from bisect import bisect_left as bl, bisect_right as br, bisect
        
mod = pow(10, 9) + 7
mod2 = 998244353
        
def inp(): return stdin.readline().strip()
def out(var, end="\n"): stdout.write(str(var)+"\n")
def outa(*var, end="\n"): stdout.write(' '.join(map(str, var)) + end)
def lmp(): return list(mp())
def mp(): return map(int, inp().split())
def smp(): return map(str, inp().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(m, val) for j in range(n)]
def remadd(x, y): return 1 if x%y else 0
def ceil(a,b): return (a+b-1)//b
  
def isprime(x):
    if x<=1: return False
    if x in (2, 3): return True
    if x%2 == 0: return False
    for i in range(3, int(sqrt(x))+1, 2):
        if x%i == 0: return False
    return True
 
def mul(arr):
    p = 1
    for i in arr: p*=i
    return p

for _ in range(int(inp())):
    n = int(inp())
    arr = lmp()
    nz = 0
    nnl, npl = [], []
    for i in range(n):
        if arr[i]>0:
            npl.append(arr[i])
        elif arr[i]==0:
            nz+=1
        else:
            nnl.append(arr[i])
    np = len(npl)
    nn = len(nnl)
    npl.sort(reverse=True)
    nnl.sort()
    ans = -inf
    if nz:
        ans = 0
    if nn>4:
        ans = max(ans, mul(nnl[:5]))
    if nn>3 and np>0:
        ans = max(ans, npl[0]*mul(nnl[:4]))
    if np>1 and nn>2: 
        ans = max(ans, mul(npl[:2])*mul(nnl[:3]))
    if np>2 and nn>1:
        ans = max(ans, mul(npl[:3])*mul(nnl[:2]))
    if np>3 and nn>0:
        ans = max(ans, mul(npl[:4])*nnl[0])
    if np>4:
        ans = max(ans, mul(npl[:5]))
    print(ans)