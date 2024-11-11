
from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,copy,time
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inp(): return int(sys.stdin.readline())
def inpl(k=0): return [int(x)+k for x in sys.stdin.readline().split()]
def inpl_str(): return list(sys.stdin.readline().split())

N = inp()

aa = [inpl(-1) for _ in range(N-2)]
cnts = [set() for _ in range(N)]
for i,(a1,a2,a3) in enumerate(aa):
    cnts[a1].add(i)
    cnts[a3].add(i)
    cnts[a2].add(i)

first = True
c2 = []
for c,s in enumerate(cnts):
    if len(s) == 1:
        if first:
            ai = list(s)[0]
            pp = [c]
            first = False
        else:
            last_ai = list(s)[0]
            last_p = c
    elif len(s) == 2:
        c2.append(c)


cnts[last_p].add(-1)
cnts[last_p].add(-2)

for c in c2:
    if last_ai in cnts[c]:
        cnts[c].add(-1)
        last_2p = c


print(cnts)

for _ in range(N-3):
    for ci in aa[ai]:
        cnts[ci].remove(ai)
        if len(cnts[ci]) == 1:
            next_ai = list(cnts[ci])[0]
            pp.append(ci)
    ai = next_ai
    print(cnts,next_ai)

pp += [last_2p, last_p]

print(' '.join([str(p+1) for p in pp]))
