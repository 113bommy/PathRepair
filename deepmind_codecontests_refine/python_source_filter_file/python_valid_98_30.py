import sys
#import random
from bisect import bisect_right as lb
from collections import deque
#sys.setrecursionlimit(10**8)
from queue import PriorityQueue as pq
from math import gcd
input_ = lambda: sys.stdin.readline().strip("\r\n")
ii = lambda : int(input_())
il = lambda : list(map(int, input_().split()))
ilf = lambda : list(map(float, input_().split()))
lii = lambda : list(map(int, list(ip())))
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
    n = ii()
    s = ip()
    fl = 0

    for i in range (n) :
        a = 0
        b = 0
        fl = 0

        for j in range (i,n) :
            a += s[j] == "a"
            b += s[j] == "b"

            print(a,b,'a')

            if (a == b) :
                print(i+1,j+1)
                fl = 1
                break
        if (fl) :
            break

    if (fl == 0) :
        print(-1,-1)
