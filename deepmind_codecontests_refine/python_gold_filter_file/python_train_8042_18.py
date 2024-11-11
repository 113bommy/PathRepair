from functools import reduce
import os
import sys
from math import *
from collections import *
from fractions import *
from bisect import *
from heapq import*
from io import BytesIO, IOBase

input = lambda: sys.stdin.readline().rstrip("\r\n")
def value():return tuple(map(int,input().split()))
def arr():return [int(i) for i in input().split()]
def sarr():return [int(i) for i in input()]
def inn():return int(input())
#----------------------------CODE------------------------------#
t=int(input())
while t:
    t-=1
    n=int(input())
    if(n%4==0):
        res=n//4
        a=[9]*(n-res)+[8]*(res)
    else:
        res=n//4
        a=[9]*(n-res-1)+[8]*(res+1)
    print(*a,sep="")