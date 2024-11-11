# coding: utf-8
import re
import math
import fractions
import random
from heapq import heappop,heappush
import time
import sys
input = sys.stdin.readline
#import numpy as np

 

 
#main
N,Q=map(int,input().split())
E=[]
for a in range(N):
    s,t,x=map(int,input().split())
    E.append((s-x,1,x))
    E.append((t-x,0,x))

for a in range(Q):
    E.append((int(input()),2,0))
E.sort()
 
S=set()
H=[]
for time_,type_,x in E:
    if type_&1:
        S.add(x)
        heappush(H,x)
    elif not type_:
        S.remove(x)
    else:
        while H and H[0] not in S:
            heappop(H)
        print(H[0] if H else -1)