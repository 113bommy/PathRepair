import math as mt 
import sys,string,bisect
input=sys.stdin.readline
import random
from collections import deque,defaultdict
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
d=defaultdict(list)
n,m,k=M()
l=L()
i=m-1
key=0
f=0
ans=10**9
while(i>=0):
    if(l[i]>0 and l[i]<=k and i!=m-1):
        key=i
        f=1
        break
    i-=1
if(f):
    ans=(abs(m-1-key)*10)
f=0
i=m-1
key2=n-1
while(i<n):
    if(l[i]>0 and l[i]<=k and i!=m-1):
        key2=i
        f=1
        break
    i+=1
if(f):
    ans=min(ans,abs(key2-m+1)*10)
    print(ans)
