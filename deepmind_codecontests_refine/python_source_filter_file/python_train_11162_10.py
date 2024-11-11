from sys import stdin, stdout
from math import floor, gcd, fabs, factorial, fmod, sqrt, inf, log, isclose
from collections import defaultdict as dd, deque
from heapq import merge, heapify, heappop, heappush, nsmallest
from bisect import bisect_left as bl, bisect_right as br, bisect
        
mod = pow(10, 9) + 7
mod2 = 998244353
        
def inp(): return stdin.readline().strip()
def iinp(): return int(inp())
def out(var, end="\n"): stdout.write(str(var)+"\n")
def outa(*var, end="\n"): stdout.write(' '.join(map(str, var)) + end)
def lmp(): return list(mp())
def mp(): return map(int, inp().split())
def smp(): return map(str, inp().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(m, val) for j in range(n)]
def remadd(x, y): return 1 if x%y else 0
def ceil(a,b): return (a+b-1)//b
S1 = 'abcdefghijklmnopqrstuvwxyz'
S2 = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
def isprime(x):
    if x<=1: return False
    if x in (2, 3): return True
    if x%2 == 0: return False
    for i in range(3, int(sqrt(x))+1, 2):
        if x%i == 0: return False
    return True
 
def findArea(a, b, c):
    area = 0.5*(a[0]*(c[1]-b[1]) + b[0]*(a[1]-c[1]) + c[0]*(b[1]-a[1]))
    return abs(area)

n = iinp()
points = []
sx, sy = 0, 0
for i in range(n):
    x, y = mp()
    sx += x
    sy += y
    points.append((x, y))
cx = sx/n
cy = sy/n
center = (cx, cy)
if n%2:
    print("NO")
    exit()
areas = []
flg = True
for i in range(n):
    area = findArea(points[i], points[(i+1)%n], center)
    areas.append(area)
pre = [0]
for i in areas:
    pre.append(i+pre[-1])
tot_area = sum(areas)
for i in range(n//2, n):
    if isclose(pre[i] - pre[i-n//2], tot_area/2, rel_tol=10**-6):
        continue
    flg = False
    break
print("YES" if flg else "NO")