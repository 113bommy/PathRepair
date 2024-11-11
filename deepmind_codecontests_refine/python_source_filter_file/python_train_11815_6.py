import sys,os,io
from sys import stdin
from math import log, gcd, ceil
from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
from bisect import bisect_left , bisect_right
import math 
def ii():
    return int(input())
def li():
    return list(map(int,input().split()))
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r") ; sys.stdout = open("output.txt","w") 
else:
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

no = "NO"
yes = "YES"


def solve():
    n,A = li()
    d = li()
    if n==1:
        if A==d[0]:
            print(d[0]-1)
        else:
            if A<d[0]:
                print(d[0]-1)
            else:
                print(0)
            return
    sd = sum(d)
    for i in range(n):
        # print(A-sd+d[i])
        minDi = max(min(d[i],A-sd+d[i]),1)
        maxDi = min(max(1,A-(n-1)),d[i])
        # print(maxDi,minDi)
        temp=0
        # if maxDi!=minDi:
        #     temp=1
        # ans=d[i]-maxDi+minDi-temp
        ans = maxDi-minDi+1
        ans=d[i]-ans
        print(ans,end=' ')
        # print(n-(maxDi-minDi),end=' ')
        # print(max(0,min(d[i],A-sd+d[i]-1)),end=' ')
    print()
    

t = 1
# t = int(input())
for _ in range(t):
    solve()
    
