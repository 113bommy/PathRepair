import sys
#import random
from bisect import bisect_left as lb
from collections import deque
#sys.setrecursionlimit(10**8)
from queue import PriorityQueue as pq
from math import *
input_ = lambda: sys.stdin.readline().strip("\r\n")
ii = lambda : int(input_())
il = lambda : list(map(int, input_().split()))
ilf = lambda : list(map(float, input_().split()))
ip = lambda : input_()
fi = lambda : float(input_())
ap = lambda ab,bc,cd : ab[bc].append(cd)
li = lambda : list(input_())
pr = lambda x : print(x)
prinT = lambda x : print(x)
f = lambda : sys.stdout.flush()
inv =lambda x:pow(x,mod-2,mod)
mod = 10**9 + 7

for _ in range (ii()) :
    n,m = il()

    m += 1
    ans = 0

    for i in range (30,-1,-1) :
        if (n>=m) :
            break

        if (n&(1<<i) == m&(1<<i)) :
            continue

        if (m%(1<<i)) :
            ans |= (1<<i)
            n |= (1<<i)

    print(ans)
