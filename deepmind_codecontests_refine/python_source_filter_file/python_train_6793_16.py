#######################################################################################################################
#   Author:     BlackFyre
#   Language:   PyPy 3.7
#######################################################################################################################
 
from sys import stdin, stdout, setrecursionlimit
from math import floor, gcd, fabs, factorial, fmod, sqrt, inf, log, log2
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
def def_inf(): return inf
def atoi(s): return ord(s)-ord('a')
def inc(s, n=1): return chr((ord(s)-ord('a')+n)%26+ord('a'))

class XY:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        
def rotate(a,b,c):
    ang = (b.y-a.y)*(c.x-b.x) - (b.x-a.x)*(c.y-b.y)
    if ang == 0: return 0   #0coll, +-clock, --aclock
    else: return ang/abs(ang)

n, p = mp()
a = lmp()
a.sort()

ans = []
for i in range(20000):
    flg = True
    for j in range(n):
        y = br(a,i+j)
        if (y-j)%p == 0:
            flg=False
            break
    if flg:
        ans.append(i)
        
print(len(ans))
print(*ans)