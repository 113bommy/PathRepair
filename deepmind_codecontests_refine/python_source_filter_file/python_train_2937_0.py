from functools import reduce
import os
import sys
from math import *
from collections import *
from fractions import *
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
# ----------------------------CODE------------------------------#
n,m=value()
if(n==1 and m==1):
    print(0)
if(n==1):
    print(*[j for j in range(2,m+2)])
else:
    j=2
    ans=[]
    for i in range(n):
        l=[j]
        for k in range(n+2,n+m+1):
            l+=[j*k]
        ans+=[l]
        j+=1
    for i in range(n):
        print(*ans[i])

