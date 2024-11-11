from collections import *
from bisect import *
from math import *
from heapq import *
from fractions import *
import sys
input=sys.stdin.readline
t=1
def r(a):
    return ((a*(a-1))//2)
while(t):
    t-=1
    a=input().rstrip("\n")
    b=int(input())
    a1=list(map(int,input().split()))
    c=1
    s=0
    for i in a:
        s+=c*(a1[ord(i)-97])
        c+=1
    v=max(a1)
    for i in a:
        s+=v*c
        c+=1
    print(s)
