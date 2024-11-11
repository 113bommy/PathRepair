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



z();__=zzz()
____=[0]*(100001)
___=0
for _ in __:
    ____[_]+=1
    ____[_-1]+=1
    ____[_+1]+=0
    if _!=1:____[_-2]==0
    ___=max(___,____[_],____[_-1])
print(___)
    
    










