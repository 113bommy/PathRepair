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

num=int(z())
for _ in range(num):
    p,f=zz()
    cnts,cnta=zz()
    s,a=zz()
    if s>a:
        s,a=a,s
        cnts,cnta=cnta,cnts

    best=0
    for i in range(cnts+1):
        if i*s<=p:
            axes=min(cnta,(p-i*s)//a)
            rest_sw=min(cnts-i,f//s)
            rest_axes=min(cnta-axes,(f-rest_sw*s)//a)
            total=i+axes+rest_sw+rest_axes
            best=max(best,total)
        
    print(best)




















    
