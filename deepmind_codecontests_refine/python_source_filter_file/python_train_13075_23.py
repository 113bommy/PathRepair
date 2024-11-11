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

n,m = rm()
a = input()
b = input()
res = math.inf
ans = []
for i in range(m-n+1):
    cal=0
    temp = []
    for j in range(n):
        if a[j] != b[i+j]:
            cal+=1
            temp.append(j+1)
    if cal < res:
        res = cal
        ans = temp
print(res)
print(*temp)