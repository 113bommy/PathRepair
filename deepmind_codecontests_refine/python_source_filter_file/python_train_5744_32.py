
# -*- coding: utf-8 -*-
# @Date    : 2019-06-26 20:12:30
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

def get_dig_sum(x):
    return (sum([int(y) for y in str(x)]) )

n = int(input())
while n < 1001:
    if get_dig_sum(n) % 4 == 0:
        print(n)
        break
    n += 1




