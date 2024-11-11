#######################################################################################################################
#   Author:     BlackFyre
#   Language:   PyPy 3.7
#######################################################################################################################
 
from sys import stdin, stdout, setrecursionlimit
from math import floor, gcd, fabs, factorial, fmod, sqrt, inf, log
from random import seed, randint
from datetime import datetime
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
 
a = lmp()
a = [0]+a+[0]
b = a.copy()
n = sum(a)
f2 = False
for kkk in range(2):
    a = b.copy()
    if a[kkk+1]>0:
        ans = l1d(n,-1)
        ans[0]=kkk
        a[kkk+1]-=1
        i=1
        flg = False
        while i<n:
            if a[ans[i-1]]>0: 
                ans[i]=ans[i-1]-1
                a[ans[i-1]]-=1
            elif a[ans[i-1]+2]>0: 
                ans[i]=ans[i-1]+1
                a[ans[i-1]+2]-=1
            else:
                flg=True
                break
            i+=1
        if not flg:
            print("YES")
            print(*ans)
            f2 = True
            break
if not f2: print("NO")