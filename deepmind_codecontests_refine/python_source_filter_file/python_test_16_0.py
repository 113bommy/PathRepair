import sys
import math
import heapq
from collections import defaultdict as dd
from collections import OrderedDict as od
from collections import deque
from itertools import permutations as pp
from itertools import combinations as cc
from sys import stdin
from functools import cmp_to_key as ctk
from functools import lru_cache
from bisect import bisect_left as bs_l
from bisect import bisect_right as bs_r
input = sys.stdin.readline
mod=10**9+7
sys.setrecursionlimit(10**5)
def comparator(x,y):
    if x[0]==y[0]:
        return x[1]-y[1]
    return True
def ncr(n, r):
    if n < r: return 0
    return fc[n] * pow(fc[r] * fc[n - r] % mod, mod - 2, mod) % mod
T=int(input())
for _ in range(T):
    n=int(input())
    arr=list(map(int,input().split()))
    hp=[]
    for i in range(n):
        if arr[i]>0:
            heapq.heappush(hp,[-arr[i],i])
    ll=[]
    while len(hp)>1:
        l1,l2=heapq.heappop(hp),heapq.heappop(hp)
        x,y=-l1[0],-l2[0]
        if x<1 or y<1:
            break
        ll.append([l1[1]+1,l2[1]+1])
        heapq.heappush(hp,[-x+1,l1[1]])
        heapq.heappush(hp,[-y+1,l1[1]])
    print(len(ll))
    for i in ll:
        print(*i)
