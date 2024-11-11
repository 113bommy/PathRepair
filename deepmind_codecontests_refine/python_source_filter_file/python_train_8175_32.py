import sys
#import random
from bisect import bisect_right as rb
from collections import deque
#sys.setrecursionlimit(10**8)
from queue import PriorityQueue
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

a = "AHIMOoTUVvWwXxY"
b = ["bd", "db", "pq", "qp"]

s = ip()

for i in range (len(s)//2) :
    if not (((s[i] in a) and (s[i]==s[-1-i])) or (s[i]+s[-1-i] in b) ) :
        print("NIE")
        exit(0)

print("TAK")
