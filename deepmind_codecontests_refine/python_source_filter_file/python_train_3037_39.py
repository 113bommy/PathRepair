from functools import reduce
import os
import sys
from collections import *
#from fractions import *
from math import *
from bisect import *
from heapq import *
from io import BytesIO, IOBase
input = lambda: sys.stdin.readline().rstrip("\r\n")
def value(): return tuple(map(int, input().split())) # multiple values
def arr(): return [int(i) for i in input().split()] # array input
def sarr(): return [int(i) for i in input()] #array from string
def starr(): return [str(x) for x in input().split()] #string array
def inn(): return int(input()) # integer input
def svalue(): return tuple(map(str, input().split())) #multiple string values
def parr(): return [(value()) for i in range(n)] # array of pairs
mo = 1000000007
inf=1e18
# ----------------------------CODE------------------------------#
n=inn()
a=arr()
pre=[]
sm=0
for i in range(n):
    sm+=a[i]
    pre+=[sm]
q=inn()
#print(pre)
for _ in range(q):
    l,r=value()
    res=pre[r-1]-pre[l-1]
    print(res//10)
