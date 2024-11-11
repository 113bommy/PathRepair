import sys
import math
import heapq
from collections import defaultdict as dd
from collections import OrderedDict as od
from collections import deque
from itertools import permutations as pp
from itertools import combinations as cc
from sys import stdin
from functools import cmp_to_key
from functools import lru_cache
from bisect import bisect_left as bs_l
from bisect import bisect_right as bs_r
input = sys.stdin.readline
mod=10**9+7
sys.setrecursionlimit(10**5)               
T=int(input())
for _ in range(T):
    n,k=map(int,input().split())
    arr=list(map(int,input().split()))
    if n>1000:
        ans=-10**9
        brr=arr[::-1]
        for i in range(1000):
            for j in range(i+1,1000):
                tmp=(n-i)*(n-j)-k*(arr[i]|arr[j])
                ans=max(ans,tmp)
        print(ans)
    else:
        ans=-10**9
        for i in range(n):
            for j in range(i+1,n):
                tmp=(i+1)*(j+1)-k*(arr[i]|arr[j])
                ans=max(ans,tmp)
        print(ans)
