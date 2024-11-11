#######################################################################################################################
#   Author:     BlackFyre
#   Language:   PyPy 3.7
#######################################################################################################################

from sys import stdin, stdout, setrecursionlimit
from math import floor, gcd, fabs, factorial, fmod, sqrt, inf, log
from collections import defaultdict as dd, deque
from heapq import merge, heapify, heappop, heappush, nsmallest
from bisect import bisect_left as bl, bisect_right as br, bisect
from collections import defaultdict as dd
mod = pow(10, 9) + 7
mod2 = 998244353
# setrecursionlimit(3000)
def inp(): return stdin.readline().strip()
def iinp(): return int(inp())
def out(var, end="\n"): stdout.write(str(var) + "\n")
def outa(*var, end="\n"): stdout.write(' '.join(map(str, var)) + end)
def lmp(): return list(mp())
def mp(): return map(int, inp().split())
def smp(): return map(str, inp().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(m, val) for j in range(n)]
def remadd(x, y): return 1 if x % y else 0
def ceil(a, b): return (a + b - 1) // b
def def_value(): return 0

for _ in range(iinp()):
    k = iinp()
    a = []
    i = 2
    while k>0:
        a.append(k%i)
        k//=i
        i+=1
    a.sort(reverse = True)
    n = len(a)
    ans = 1
    for i in range(n):
        j = i
        cnt = 0
        while j>=0 and a[j]==a[i]:
            j-=1
            cnt+=1
        ans *= (max(0,n-max(0,a[i]-1)-i)/cnt)
    ans-=1
    if(a.count(0)==0): zero=0
    else: zero=1
    for i in range(n):
        if a[i]==0: break
        j = i
        cnt = 0
        while j>=0 and a[j]==a[i]:
            j-=1
            cnt+=1
        zero *= (max(0,n-max(0,a[i]-1)-i-1)/cnt)
    print(int(ans-zero))