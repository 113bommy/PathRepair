import sys
from functools import lru_cache, cmp_to_key
from heapq import merge, heapify, heappop, heappush, nsmallest
from math import ceil, floor, gcd, fabs, factorial, fmod, sqrt, inf
from collections import defaultdict as dd, deque, Counter as C
from itertools import combinations as comb, permutations as perm
from bisect import bisect_left as bl, bisect_right as br, bisect
from time import perf_counter
from fractions import Fraction
# sys.setrecursionlimit(pow(10, 6))
# sys.stdin = open("input.txt", "r")
# sys.stdout = open("output.txt", "w")
mod = pow(10, 9) + 7
mod2 = 998244353
def data(): return sys.stdin.readline().strip()
def out(*var, end="\n"): sys.stdout.write(' '.join(map(str, var))+end)
def l(): return list(sp())
def sl(): return list(ssp())
def sp(): return map(int, data().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]

"""





                            pppppppppppppppppppp
                         ppppp  ppppppppppppppppppp
                      ppppppp    ppppppppppppppppppppp
                      pppppppp  pppppppppppppppppppppp
                      pppppppppppppppppppppppppppppppp
                              pppppppppppppppppppppppp
       ppppppppppppppppppppppppppppppppppppppppppppppp  pppppppppppppppppppp
      pppppppppppppppppppppppppppppppppppppppppppppppp  ppppppppppppppppppppp
     ppppppppppppppppppppppppppppppppppppppppppppppppp  pppppppppppppppppppppp
    ppppppppppppppppppppppppppppppppppppppppppppppp    pppppppppppppppppppppppp
   pppppppppppppppppppppppppppppppppppppppppppppp     pppppppppppppppppppppppppp
  ppppppppppppppppppppppppppppppppppppppppppppp      pppppppppppppppppppppppppppp
  pppppppppppppppppppppppppppppppp               pppppppppppppppppppppppppppppppp
  pppppppppppppppppppppppppppp     pppppppppppppppppppppppppppppppppppppppppppppp
  ppppppppppppppppppppppppppp    pppppppppppppppppppppppppppppppppppppppppppppppp
    pppppppppppppppppppppppp  pppppppppppppppppppppppppppppppppppppppppppppppppp
     ppppppppppppppppppppppp  ppppppppppppppppppppppppppppppppppppppppppppppppp
      pppppppppppppppppppppp  ppppppppppppppppppppppppppppppppppppppppppppppp
       ppppppppppppppppppppp  ppppppppppppppppppppppppppppppppppppppppppppp
                              pppppppppppppppppppppppp
                              pppppppppppppppppppppppppppppppp
                              pppppppppppppppppppppp  pppppppp
                              ppppppppppppppppppppp    ppppppp
                                 ppppppppppppppppppp  ppppp
                                    pppppppppppppppppppp
                                                            
                                                            
                                                            
                                                            
                                                            
"""


def cmp(a, b):
    if a[1] > b[1]:
        return -1
    if a[1] < b[1]:
        return 1
    if a[0][0] < b[0][0]:
        return -1
    return 1


name = data()
n = int(data())
score = dd(int)
for i in range(n):
    arr = sl()
    if arr[1] == 'posted':
        temp = arr[3][:len(arr[3])-2]
        if temp == name:
            score[(arr[0], temp)] += 15
        elif arr[0] == name:
            score[(temp, arr[0])] += 15
        else:
            score[(temp, name)] = 0
            score[(arr[0], name)] = 0
    if arr[1] == 'commented':
        temp = arr[3][:len(arr[3])-2]
        if temp == name:
            score[(arr[0], temp)] += 10
        elif arr[0] == name:
            score[(temp, arr[0])] += 10
        else:
            score[(temp, name)] = 0
            score[(arr[0], name)] = 0
    if arr[1] == 'likes':
        temp = arr[2][:len(arr[2]) - 2]
        if temp == name:
            score[(arr[0], temp)] += 5
        elif arr[0] == name:
            score[(temp, arr[0])] += 5
        else:
            score[(temp, name)] = 0
            score[(arr[0], name)] = 0
score = sorted(score.items(), key=cmp_to_key(cmp))
for i in score:
    if i[0][1] == name:
        out(i[0][0])
