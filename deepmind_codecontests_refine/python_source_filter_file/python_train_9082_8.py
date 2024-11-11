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
def sarr():return [i for i in input().split()]
#----------------------------CODE------------------------------#

t=int(input())
while t:
    t-=1
    l,r,m=value()
    for i in range(l,r+1):
        if(m%i==0):
            print(i,r,r)
            break
        else:
            #print("Hello")
            res=m%i
            if(i-res<=r-l):
                #print("yes")
                print(i,r-(i-res),r)
                break
            if(res<=r-l):
                print(i,(r-res),r)
                break

