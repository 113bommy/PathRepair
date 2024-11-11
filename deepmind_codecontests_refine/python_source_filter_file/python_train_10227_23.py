fast=lambda:stdin.readline().strip()
zzz=lambda:[int(i) for i in fast().split()]
z,zz=input,lambda:list(map(int,z().split()))
szz,graph,mod,szzz=lambda:sorted(zz()),{},10**9+7,lambda:sorted(zzz())
from re import *
from sys import *
from math import *
from heapq import *
from queue import *
from bisect import *
from string import *
from itertools import *
from collections import *
from math import factorial as f
from bisect import bisect as bs
from bisect import bisect_left as bsl
from collections import Counter as cc
from itertools import accumulate as ac
def lcd(xnum1,xnum2):return (xnum1*xnum2//gcd(xnum1,xnum2))
def output(answer):stdout.write(str(answer))
###########################---Test-Case---#################################
"""

  If you Know me , Then you probably don't know me !


"""
###########################---START-CODING---##############################

num=int(z())

for _ in range( num ):
    n,k=zzz()
    if n%2==k%2 and k<=n:
        print('YES')
    else:
        print('NO')



    
        
        
        
    





