# cook your dish here
import sys
#import random
from bisect import bisect_left as lb
from bisect import bisect_right as rb
from collections import deque
#sys.setrecursionlimit(10**8)
from queue import PriorityQueue as pq
from math import gcd
#import math
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
dx = [0,0,1,-1]
dy = [1,-1,0,0]
mod = 10**9 + 7
mod1 = 998244353

for _ in range (ii()) :
    n = ii()
    a = il()
    b = il()

    ans = ['0' for i in range (n)]

    ind = -1
    ind1 = -1

    x = max(a)
    y = max(b)

    for i in range (n) :
        if (a[i] == x) :
            ind = i
        if (b[i] == y) :
            ind1 = i

    if (ind == ind1) :
        ans[ind] = '1'
        print(''.join(ans))
        continue
            
    c = [[a[i],i] for i in range (n)]
    d = [[b[i],i] for i in range (n)]

    c.sort(reverse = True)
    d.sort(reverse = True)

    r = a[d[0][1]]
    r1 = b[c[0][1]]
    i = 0
    j = 0

    while (i < n and j < n) :
        fl = 0
        if (c[i][0] >= r) :
            r1 = min(r1,b[c[i][1]])
            i += 1
            fl = 1
        if (d[j][0] >= r1) :
            r = min(r,a[d[j][1]])
            j += 1
            fl = 1

        if (fl) == 0 :
            break

    for i in range (n) :
        if (r <= c[i][0]) :
            ans[c[i][1]] = '1'

    for i in range (n) :
        if (r1 <= c[i][0]) :
            ans[c[i][1]] = '1'

    
    print(''.join(ans))

    








    
