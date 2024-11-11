z,zz,dgraphs=input,lambda:list(map(int,z().split())),{}
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
        if x%i==0:return 0
    return 1
def dfs(u,visit,graph):
    visit[u]=True
    for i in graph[u]:
        if not visit[i]:
            dfs(i,visit,graph)
################################################################################

"""

led=(6,2,5,5,4,5,6,3,7,6)

vowel={'a':0,'e':0,'i':0,'o':0,'u':0}

color4=["G", "GB", "YGB", "YGBI", "OYGBI" ,"OYGBIV",'ROYGBIV' ]
z,zz,dgraphs=input,lambda:list(map(int,z().split())),{}
d,l,r,b=[],0,1,{}
for _ in range(int(z())):d.append(z().split())
for i in d:
    id_ =int(i[1])
    if i[0]=='L':
        b[id_]=l
        l-=1
    if i[0]=='R':
        b[id_]=r
        r+=1
    if i[0]=='?':
        p = b[id_]
        print(min(p-l-1,r-p-1))
    
    
"""

###########################---START-CODING---####################################
n,w=zz()
l=zz()

mi,mx=0,0
t=0
for i in l:
    t+=i
    mx=max(t,mx)
    mi=min(mi,t)
print(max(0,w-mx+1+mi))
    
    
    
    
    

    
