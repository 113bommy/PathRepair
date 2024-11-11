#import sys
#import numpy as np
import math
#from fractions import Fraction
import itertools
from collections import deque
from collections import Counter
import heapq
from fractions  import gcd
#input=sys.stdin.readline
import bisect
n=int(input())
arr=[list(input().split()) for _ in range(n)]
yaxis={}
xaxis={}
s1axis={}
s2axis={}
t1axis={}
t2axis={}

t=list()

for i in range(n):
    x,y,u=arr[i]
    x=int(x)
    y=int(y)
    if u=="U" or u=="R":
        if x+y not in s1axis:
            s1axis[x+y]=[[y,u]]
        else:
            s1axis[x+y].append([y,u])
    if u=="D" or u=="L":
        if x+y not in s2axis:
            s2axis[x+y]=[[y,u]]
        else:
            s2axis[x+y].append([y,u])
    if u=="U" or u=="L":
        if y-x not in t1axis:
            t1axis[y-x]=[[y,u]]
        else:
            t1axis[y-x].append([y,u])
    if u=="D" or u=="R":
        if y-x not in t2axis:
            t2axis[y-x]=[[y,u]]
        else:
            t2axis[y-x].append([y,u])
    if u=="U" or u=="D":
        if x in xaxis:
            xaxis[x].append([y,u])
        else:
            xaxis[x]=[[y,u]]
    else:
        if y in yaxis:
            yaxis[y].append([x,u])
        else:
            yaxis[y]=[[x,u]]

for s in xaxis:
    s=sorted(xaxis[s],key=lambda x: x[0])
    for k in range(1,len(s)):
        if s[k-1][1]=="U" and s[k][1]=="D":
            time=(s[k][0]-s[k-1][0])*5
            heapq.heappush(t,time)
for s in yaxis:
    s=sorted(yaxis[s],key=lambda x: x[0])
    for k in range(1,len(s)):
        if s[k-1][1]=="R" and s[k][1]=="L":
            time=(s[k][0]-s[k-1][0])*5
            heapq.heappush(t,time)
for s in s1axis:
    s=sorted(s1axis[s],key=lambda x: x[0])
    for k in range(1,len(s)):
        if s[k-1][1]=="U" and (s[k][1]=="R" or s[k][1]=="L"):
            time=10*(s[k][0]-s[k-1][0])
            heapq.heappush(t,time)

for s in s2axis:
    s=sorted(s2axis[s],key=lambda x: x[0])
    for k in range(1,len(s)):
        if s[k-1][1]=="L" and s[k][1]=="D":
            time=10*(s[k][0]-s[k-1][0])
            heapq.heappush(t,time)
 
for s in t1axis:
    s=sorted(t1axis[s],key=lambda x: x[0])
    for k in range(1,len(s)):
        if s[k-1][1]=="R" and s[k][1]=="D":
            time=10*(s[k][0]-s[k-1][0])
            heapq.heappush(t,time)

for s in t2axis:
    s=sorted(t2axis[s],key=lambda x: x[0])
    for k in range(1,len(s)):
        if s[k-1][1]=="U" and s[k][1]=="L":
            time=10*(s[k][0]-s[k-1][0])
            heapq.heappush(t,time)
if not t:
  print("SAFE")
else:
  print(heapq.heappop(t))