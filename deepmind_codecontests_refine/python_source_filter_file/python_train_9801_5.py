
# -*- coding: utf-8 -*-
# @Date    : 2019-03-05 20:47:27
# @Author  : raj lath (oorja.halt@gmail.com)
# @Link    : link
# @Version : 1.0.0

import sys
sys.setrecursionlimit(10**5+1)

inf     =  int(10 ** 20)
max_val =  inf
min_val = -inf

RW  = lambda : sys.stdin.readline().strip()
RI  = lambda : int(RW())
RMI = lambda : [int(x) for x in sys.stdin.readline().strip().split()]
RWI = lambda : [x for x in sys.stdin.readline().strip().split()]


nb = RI()
cost = sorted(RMI(), reverse=True)
print(cost)
sums = sum(cost)
nb_query= RI()
queries = RMI()
#print(queries)
for i in queries:
    print(sums - cost[i-1])
