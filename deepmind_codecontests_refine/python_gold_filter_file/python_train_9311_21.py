import math;
from math import log2,sqrt;
import sys;
sys.setrecursionlimit(pow(10,6))
import collections
from collections import defaultdict
from statistics import median
inf = float("inf")
mod=pow(10,9)+7
def gen_left(a):
    l=[0]*n;
    for i in range(1,len(l)):
        if a[i]>a[i-1]:
            l[i]=l[i-1]+1;
    return l;
def gen_right(a):
    r=[0]*n;
    for i in reversed(range(len(l)-1)):
        if a[i]<a[i+1]:
            r[i]=r[i+1]+1
    return r;
def generate(a,l,r):
    ans=0
    for i in range(n):
        if i==0:
            ans=max(ans,r[i+1]+1+1)
        elif i==n-1:
            ans=max(ans,l[n-2]+1+1)
        elif a[i-1]+1<a[i+1]:
            ans=max(ans,r[i+1]+1+l[i-1]+1+1)
        else:
            ans=max(ans,r[i+1]+1+1,l[i-1]+1+1)
    return ans;
t=1;
for i in range(t):
    n=int(input())
    a = list(map(int, input().split()))
    if n==1:
        print(1)
        continue
    if n==2:
        print(2)
        continue

    l=gen_left(a)
    r=gen_right(a)
    ans=generate(a,l,r)
    print(ans)


