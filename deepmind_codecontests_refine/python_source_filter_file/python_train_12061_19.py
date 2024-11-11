from collections import Counter,defaultdict,deque
from heapq import heappop,heappush,heapify
import sys,bisect,math,itertools,fractions,pprint
sys.setrecursionlimit(10**8)
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

n,W = inpl() 
a = [inpl() for _ in range(n)]
a.sort(key = lambda x:x[1], reverse = True)
a.sort()
b = []
now = a[0][0]
li = []
for i in range(n):
    w,v = a[i]
    if now == w:
        li.append(v)
    else:
        now = w
        b.append(li)
        li = []
        li.append(v)
if li != []: b.append(li)
kind = now - a[0][0] + 1
f = a[0][0]
for i in range(len(b)):
    b[i] = b[i][::-1]

c = [[0] for _ in range(4)]
for i,l in enumerate(b):
    for x in l:
        c[i].append(c[i][-1] + x)
    c[i] = c[i]
print(c)
ln = [len(x) for x in c]
res = 0
def chk(w,v):
    global res
    if w <= W:
        res = max(res, v)
x,y,z,w = ln
print(ln)
for i in range(x):
    for j in range(y):
        for k in range(z):
            for l in range(w):
                ww = i*f+j*(f+1)+k*(f+2)+l*(f+3)
                v = c[0][i] + c[1][j] + c[2][k] + c[3][l]
                if ww <= W: res = max(res, v)
                # print(ww,v)
print(res)
