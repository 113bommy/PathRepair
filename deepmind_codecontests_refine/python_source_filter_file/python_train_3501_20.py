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

vowel={'a':0,'e':0,'i':0,'o':0,'u':0}

color4=["G", "GB", "YGB", "YGBI", "OYGBI" ,"OYGBIV",'ROYGBIV' ]

 
"""

###########################---START-CODING---####################################

n,m=zz()

l=z()

for _ in range(m):
    a,b,c,d=z().split()
    a=int(a)
    b=int(b)
    a=a-1
    for i in l[a:b+1]:
        if i==c:
            x=d
            l=l[:a]+x+l[a+1:]
        a+=1

print(l)
        
