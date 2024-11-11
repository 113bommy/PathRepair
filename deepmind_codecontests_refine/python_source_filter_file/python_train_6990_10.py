import math
import time
from collections import defaultdict,deque,Counter
from sys import stdin,stdout
from bisect import bisect_left,bisect_right
from queue import PriorityQueue 
import sys
n,m=map(int,stdin.readline().split())
grid=[]
for _ in range(n):
    grid.append(list(map(int,stdin.readline().split())))
ans=0
ansL=[1]*n
for i in range(n):
    ans^=grid[i][0]
if(ans!=0):
    print("TAK")
    print(*ansL)
else:
    found=False
    for row in range(n):
        for col in range(1,m):
            if(grid[row][col]!=grid[row][0]):
                found=True
                ansL[row]=col+1
                break
            if(found):
                break
    if(found):
        print("TAK")
        print(*ansL)
    else:
        print("NIE")