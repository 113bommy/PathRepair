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
ls = lambda : list(input().strip()) # for strings to list of char
from collections import defaultdict as df
import heapq 
#heapq.heapify(li) heappush(li,4) heappop(li)
#import random
#random.shuffle(list)
infinite = float('inf')
#######################################################################

d={} 
for i in range(4):
    s=input().strip()
    d[s[0]]=len(s[2:])

p={}
for i in d:
    for j in d:
        if(i!=j and not(d[i]>=2*d[j])):
            p[i]=1
temp=-1
if(len(p)==3):
    p=set(p)
    k=p.symmetric_difference({'A','B','C','D'})
    k=list(k)
    temp=k[0]
p={}
temp2=-1
for i in d:
    for j in d:
        if(i!=j and not(2*d[i]<=d[j])):
            p[i]=1
if(len(p)==3):
    p=set(p)
    k=p.symmetric_difference({'A','B','C','D'})
    k=list(k)
    temp2=k[0]

if(temp==-1 and temp2==-1):
    print("C")
elif(temp==temp2 and temp!=-1):
    print(temp)
elif(temp!=-1  and temp2!=-1 and temp!=temp2):
    print("C")
elif(temp!=-1):
    print(temp)
elif(temp2!=-1):
    print(temp)
else:
    print("C")
