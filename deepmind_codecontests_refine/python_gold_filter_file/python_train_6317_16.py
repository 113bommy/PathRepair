z,zz=input,lambda:list(map(int,z().split()))
zzz=lambda:[int(i) for i in stdin.readline().split()]
szz,graph,mod,szzz=lambda:sorted(zz()),{},10**9+7,lambda:sorted(zzz())
from string import *
from re import *
from collections import *
from queue import *
from sys import *
from collections import *
from math import *
from heapq import *
from itertools import *
from bisect import *
from collections import Counter as cc
from math import factorial as f
from bisect import bisect as bs
from bisect import bisect_left as bsl
from itertools import accumulate as ac
def lcd(xnum1,xnum2):return (xnum1*xnum2//gcd(xnum1,xnum2))
def prime(x):
    p=ceil(x**.5)+1
    for i in range(2,p):
        if (x%i==0 and x!=2) or x==0:return 0
        
    return 1
def dfs(u,visit,graph):
    visit[u]=True
    for i in graph[u]:
        if not visit[i]:
            dfs(i,visit,graph)

###########################---Test-Case---#################################
"""




"""
###########################---START-CODING---##############################

n,k=zz()
arr=zzz()
l,r=0,n-1
c=0
d=0
while l<=r:
    if arr[l]<=k:
        l+=1
    else:
        c=1
    if arr[r]<=k:
        r-=1
    else:
        d=1
    if c+d==2:
        break
    
print(min(n,l+(n-r-1)))







    

    
        
    
        
