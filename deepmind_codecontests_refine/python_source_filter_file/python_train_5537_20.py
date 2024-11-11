import sys
input=sys.stdin.readline
from collections import defaultdict as dc
from collections import Counter
from bisect import bisect_right, bisect_left
import math
from operator import itemgetter
from heapq import heapify, heappop, heappush
from queue import PriorityQueue as pq
a1=int(input())
a2=int(input())
k1=int(input())
k2=int(input())
n=int(input())
if k1>k2:
    a1,a2=a2,a1
    k1,k2=k2,k1
x,y=0,0
if n==a1*k1+a2*k2:
    print(a1+a2,a1+a2)
else:
    a=n
    a-=a2*(k2-1)
    a-=a1*(k1-1)
    if a<=0:
        x=0
    else:
        x=a1+a2-a
    y=0
    a=n
    while(a>0 and a1):
        #print('str1')
        if a-k1>=0:
            y+=1
            a-=k1
            a1-=1
        else:
            a=0
    while(a>0 and a2):
        #print('str2')
        if a-k2>=0:
            y+=1
            a-=k2
            a2-=1
        else:
            a=0
    print(x,y)
        
    
    