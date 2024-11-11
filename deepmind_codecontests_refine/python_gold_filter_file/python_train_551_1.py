import sys
#import random
from bisect import bisect_left as lb
from collections import deque
#sys.setrecursionlimit(10**8)
from queue import PriorityQueue as pq
#from math import *
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

n = ii()

a = []

for i in range (n) :
    x,y = il()

    a.append([x,y])

a.sort(key = lambda i : i[1])

ind = n-1

#print(a)

ans = 0
t = 0

for i in range (n) :
    x = a[i][1]
    t1 = t
    #print(ind,i)
    if (t < x) :
        for j in range (ind,i-1,-1) :
     #       print(1)
            y = a[j][0]

            if (t+y) >= x :
                z = min(x-t,y)
                a[j][0] -= z
                if(a[j][0] == 0) :
                    ind -= 1
                t += z
                break
                
            else :
                t += y
                a[j][0] = 0
                ind -= 1

    ans += (t-t1)*2

    #print(t1,t,ind,i,a)

    if (t >= x) :
        ans += a[i][0]
        t += a[i][0]
        a[i][0] = 0
    else :
        ans += 2*a[i][0]
        t += a[i][0]
        a[i][0] = 0
    
    #print(ans,'a')


print(ans)
