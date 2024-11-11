import sys
#import random
from bisect import bisect_left as lb
from bisect import bisect_right as rb
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
mod1 = 998244353

n,m  = il()

a = []

for i in range (n) :
    a.append(list(ip()))

pre = [0 for i in range (m+1)]

for i in range (1,m) :
    for j in range (n) :
        if (a[j-1][i] == 'X' and a[j][i-1] == "X") :
            pre[i] += 1
q = ii()
for i in range (1,m+1) :
    pre[i] += pre[i-1]

#print(*pre)

for i in range (q) :
    x,y = il()

    if (x == y) :
        print("YES")
        continue

    t = pre[y-1] - pre[x-1]

    if (t > 0) :
        print("NO")
    else :
        print("YES")
    
