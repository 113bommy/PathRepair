import sys
from math import gcd
from heapq import heappop
from heapq import heappush
from heapq import heapify
from bisect import insort
from bisect import bisect_right
from bisect import bisect_left
from sys import stdin,stdout
from collections import defaultdict, deque
from math import log2, ceil, floor

inp=lambda : int(input())
sip=lambda : input()
mulip =lambda : map(int,input().split())
lst=lambda : list(map(int,input().split()))
slst=lambda: list(sip())
arr2d= lambda x: [[int(j) for j in input().split()] for i in range(x)]
odds = lambda l: len(list(filter(lambda x: x%2!=0, l)))
evens = lambda l: len(list(filter(lambda x: x%2==0, l)))
mod = pow(10,9)+7
#-------------------------------------------------------
Judge = 0
if Judge:
    sys.stdin = open("input.in",'r')
    #sys.stdout = open("output.in",'w')

n,m = mulip()
a = lst()
b = lst()
a = sorted(a)
b = sorted(b)
if m==1 or a==b:
    print(0)
else:
    ans = pow(10,9)+7
    mn = min(b)
    cnt = 0
    for i in b:
        if i==mn:
            cnt+=1
    d = defaultdict(int)
    for i in a:
        d[i]+=1
    for i in d:
        if d[i]==cnt:
            rem = m-i+mn 
            x = list(a)
            for i in range(n):
                x[i] = (x[i]+rem)%m 
            x = sorted(x)
            if x==b:
                ans = min(ans,rem)
    print(ans)





