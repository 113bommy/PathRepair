from collections import defaultdict as dc
from collections import Counter 
from heapq import *
import math
from bisect import bisect_left,bisect
#bisect gives x and p[x] is element greater than it and out of bound for last one 
#p[x-1] gives equal or smaller and no error for any element.
import sys
from collections import deque as dq
from heapq import heapify,heappush,heappop
mod=10**9 +7
def sinp():
    p=str(input())
    return p
def seive(n):
    p=[0]*(n+1)
    for i in range(2,n):
        if p[i]==0:
            for j in range(2*i,n+1,i):
                p[i]=1
    return p
def inp(): 
    p=int(input())
    return p
def line():
    p=list(map(int,input().split()))
    return p
def read_mat():
    n=inp()
    a=[]
    for i in range(n):
        a.append(line())
    return a
def digit(n):
    s=str(n)
    p=0
    for i in s:
        p+=(int(i))**2
    return p

def solve(a,k):
    s=1
    while(s<k):
        s+=1
        p=list(str(a))
        r=max(p)
        l=min(p)
        if l=='0' or r=='0':
            return 0
        # print(int(r)*int(l),l,r)
        a=a+int(r)*int(l)
    return a


for test in range(inp()):
    a,k=line()
    l=solve(a,k)
    print(l)