import sys
import math
import heapq
from collections import defaultdict as dd
from itertools import permutations as pp
from itertools import combinations as cc
from sys import stdin
from functools import cmp_to_key
input=stdin.readline
m=10**9+7
sys.setrecursionlimit(10**5)
T=int(input())
for _ in range(T):
    n=int(input())
    d=0
    while n:
        d+=1
        n//=10
        num=n%10
    ans=10*(num-1)
    for i in range(d):
        ans+=(i+1)
    print(ans)