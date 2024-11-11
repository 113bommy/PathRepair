import math as mt 
import sys,string
input=sys.stdin.readline
#print=sys.stdout.write
import random
from collections import deque,defaultdict
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
n,k,p=M()
l=L()
g=L()
l.sort()
g.sort()
ans=10**10
for i in range(k-n):
    ans1=0
    for j in range(i,i+n):
        ans1=max(ans1,abs(l[j-i]-g[j])+abs(g[j]-p))
    ans=min(ans,ans1)
print(ans)
    
