######################################################################
# Write your code here
import sys
from math import *
input = sys.stdin.readline
#import resource
#resource.setrlimit(resource.RLIMIT_STACK, [0x10000000, resource.RLIM_INFINITY])
#sys.setrecursionlimit(0x100000)
# Write your code here
RI = lambda : [int(x) for x in sys.stdin.readline().strip().split()]
rw = lambda : input().strip().split()
from collections import defaultdict as df
import heapq 
#heapq.heapify(li) heappush(li,4) heappop(li)
#import random
#random.shuffle(list)
infinite = float('inf')
#######################################################################

n,d=RI()
l=RI()

i=n-1
flag=0
c=0
while(d>0 and i>=0):
    if(d>=l[i]):
        d-=l[i]
        i-=1
    else:
        flag=1
        break
    if(d>=10):
        d-=10
        c+=2
    else:
        break

#print(i)
#print(c)
#print(flag)
#print(d)
if(i!=-1):
    print(-1)
else:
    while(d>=5):
        d-=5
        c+=1
    print(c)
