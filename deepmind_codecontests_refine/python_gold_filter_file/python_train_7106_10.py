z,zz=input,lambda:list(map(int,z().split()));
szz,dgraphs,mod=lambda:sorted(zz()),{},10**9+7
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

"""

###########################---START-CODING---####################################

n,m=zz()

a=zz()
b=zz()

for i in range(2**9):
    for j in range(n):
        for k in range(m):
            if i|(a[j]&b[k])==i:
                break
        else:break
    else:
        print(i)
        exit()

                








        

