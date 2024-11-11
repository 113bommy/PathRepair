# Template 1.0
import sys, re, math
from collections import deque, defaultdict, Counter, OrderedDict
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, gcd
from heapq import heappush, heappop, heapify, nlargest, nsmallest
def STR(): return list(input())
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def list2d(a, b, c): return [[c] * b for i in range(a)]
def sortListWithIndex(listOfTuples, idx):   return (sorted(listOfTuples, key=lambda x: x[idx]))
def sortDictWithVal(passedDic):
    temp = sorted(passedDic.items(), key=lambda kv: (kv[1], kv[0]))[::-1]
    toret = {}
    for tup in temp:
        toret[tup[0]] = tup[1]
    return toret
def sortDictWithKey(passedDic):
    return dict(OrderedDict(sorted(passedDic.items())))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7


req = []

for i in range(1, 30000):
    req.append(i*(3*i+1)//2)
# print(req[-1])
t = INT()

while (t != 0):
    n = INT()
    ans = 0
    while(n>1):
        lo = 0
        hi = 29999
        temp = 0
        while(lo<hi):

            mid = (lo+hi)//2
            if(req[mid]>n):
                hi = mid
            elif(req[mid]==n):
                temp = req[mid]
                lo = mid
                break
            else:
                temp = req[mid]
                lo = mid + 1
        # print(temp, n)
        n-=temp
        ans +=1

    print(ans)
    t -= 1


