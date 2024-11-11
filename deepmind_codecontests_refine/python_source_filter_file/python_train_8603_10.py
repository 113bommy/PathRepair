z,zz,dgraphs,mod=input,lambda:list(map(int,z().split())),{},10**9+7
from string import *
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
def lcd(xnum1,xnum2):return (xnum1*xnum2//gcd(xnum1,xnum2))
def prime(x):
    p=ceil(x**.5)+1
    for i in range(2,p):
        if x%i==0 and x!=2:return 0
    return 1
def dfs(u,visit,graph):
    visit[u]=True
    for i in graph[u]:
        if not visit[i]:
            dfs(i,visit,graph)
################################################################################

"""

led=(6,2,5,5,4,5,6,3,7,6)

color4=["G", "GB", "YGB", "YGBI", "OYGBI" ,"OYGBIV",'ROYGBIV' ]
19 3
5 4 10
"""

###########################---START-CODING---####################################

n,k=zz()
l=z()
s1=sorted(set(l))
if k>n:
    print(l+s1[0]*(k-1))
else:
    i=k-1
    while l[i]>=s1[-1] and i>-1:
        i-=1
    d=s1.index(l[i])
    print(l[:i]+s1[d+1]+s1[0]*(k-i-1))

