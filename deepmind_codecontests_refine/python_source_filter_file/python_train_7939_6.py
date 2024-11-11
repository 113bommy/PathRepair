from math import *
from bisect import *
from collections import *
from random import *
from decimal import *
import sys
input=sys.stdin.readline
def inp():
    return int(input())
def st():
    return input().rstrip('\n')
def lis():
    return list(map(int,input().split()))
def ma():
    return map(int,input().split())
t=1
while(t):
    t-=1
    n=inp()
    a=lis()
    r=[0 for i in range(n)]
    a.sort()
    i,j=0,n-1
    for k in range(n):
        if(k%2==0):
            r[k]=a[j]
            j-=1
        else:
            r[k]=a[i]
            i+=1
    s=0
    for i in range(1,n-1):
       if(r[i]<r[i-1] and r[i]<r[i+1]):
           s+=1
    print(s)
    print(*r)
