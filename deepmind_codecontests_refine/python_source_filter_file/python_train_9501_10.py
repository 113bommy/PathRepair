import os
import sys
import math
import heapq
from decimal import *
from io import BytesIO, IOBase
from collections import defaultdict, deque

def r():
    return int(input())
def rm():
    return map(int,input().split())
def rl():
    return list(map(int,input().split()))

for _ in range(r()):
    n = r()
    a = input()
    ans = True
    for i in range(1,n):
        if a[i]!=a[i-1]:
            ans=False
    if ans:
        if n <= 2:
            print(0)
        elif n==3:
            print(1)
        else:
            print((n+2)//3)
    else:
        b = [1]
        for i in range(1,n):
            if a[i]==a[i-1]:
                b[-1]+=1
            else:
                b.append(1)
        if a[0]==a[-1]:
            b[0]+=b[-1]
        b = b[:-1]
        b.sort(reverse=True)
        i=0
        cnt=0
        while i<len(b) and b[i]>=3:
            cnt+=b[i]//3
            i+=1
        print(cnt)