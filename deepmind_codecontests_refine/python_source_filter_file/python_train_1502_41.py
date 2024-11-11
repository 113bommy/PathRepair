#This code is contributed by Siddharth
from bisect import *
import math
from collections import *
from heapq import *
from itertools import *
inf=10**18
mod=10**9+7

# ---------------------------------------------------------Code---------------------------------------------------------


s=input()
nb,ns,nc=map(int,input().split())
pb,ps,pc=map(int,input().split())
r=int(input())
cnt=Counter(s)
maxx=r
i=0
l=1000000000000
while i<l:
    mid=(i+l)//2
    temp=max(0,cnt['B']*mid-nb)*pb+max(0,cnt['C']*mid-nc)*pc+max(0,cnt['S']*mid-ns)*ps
    if r<temp:
        l=mid
    else:
        i=mid+1

print(l-1)























