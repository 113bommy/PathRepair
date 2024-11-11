import sys, os.path
from collections import*
from copy import*
import math
mod=10**9+7
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")
n,k=map(int,input().split())
a=list(map(int,input().split()))
d={}

j=0
for i in a:
    if(len(d)==k):
        break
    d[i]=j
    j+=1
if(len(d)==k):
    print(min(d.values()),max(d.values()))
else:
    print(-1,-1)
        