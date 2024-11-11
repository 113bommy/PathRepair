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
    n=int(input())
    s1=input().strip()
    s2=input().strip()
    l1=list(s1)
    l2=list(s2)
    l3,l4=l1.copy(),l2.copy()
    ans1,ans2=0,0
    for i in range(n):
        if l2[i]=='1':
            if i-1>=0 and l1[i-1]=='1':
                l1[i-1]='2'
                ans1+=1
            elif l1[i]=='0':
                l1[i]='2'
                ans1+=1
            elif i+1<n and l1[i+1]=='1':
                l1[i+1]='2'
                ans1+=1
                
    for i in range(n-1):
        if l4[i]=='1':
            if i+1<n and l3[i+1]=='1':
                l1[i+1]='2'
                ans2+=1
            elif l3[i]=='0':
                l3[i]='2'
                ans2+=1
            elif i-1>=0 and l3[i-1]=='1':
                l3[i-1]='2'
                ans2+=1
    
    print(max(ans1,ans2))
