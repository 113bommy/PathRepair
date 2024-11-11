import math;
from math import log2,sqrt;
from bisect import bisect_left,bisect_right
import bisect;
import sys;
from sys import stdin,stdout
import os
sys.setrecursionlimit(pow(10,7))
import collections
from collections import defaultdict
from statistics import median
# input=stdin.readline
# print=stdout.write
from queue import Queue
inf = float("inf")

n,k=map(int,input().split())
l=list(map(int,input().split()))
zeros=0;
it1=0;
it2=0;
maxa=0;
pointer1=0;
pointer2=0;
while it1<n and it2<n:
    if l[it2]:
        pass
    elif k>0:
        k-=1
    else:
        while l[it1]:
            it1+=1;
        it1+=1;
    now=it2-it1+1;
    if now>maxa:
        maxa=now;
        pointer1=it1;
        pointer2=it2;
    it2+=1
for i in range(pointer1,pointer2+1):
    l[i]=1;
print(maxa)
print(*l)