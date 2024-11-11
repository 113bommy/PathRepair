import math
import sys

n,k=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
cnt=0
cut=1
f=0
for i in a:
    if i==cut or i>cut :
        cnt+=(i-1)
        cut+=1
        f=1
    elif i<cut:
        cnt+=(i-1)
        cut=i
        f=-1
if f==1:
    cut-=1
if a[-1]>cut:
    cnt-=(a[-1]-cut)
print(cnt)