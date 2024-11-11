from itertools import accumulate as ac
from collections import Counter as cc
from bisect import bisect_left as bsl
from bisect import bisect as bs
from math import factorial as f
from collections import *
from itertools import *
from string import *
from bisect import *
from queue import *
from heapq import *
from math import *
from sys import *
from re import *
def fast(): return stdin.readline().strip()
def zzz(): return [int(i) for i in fast().split()]


z, zz = input, lambda: list(map(int, z().split()))
szz, graph, mod, szzz = lambda: sorted(
    zz()), {}, 10**9+7, lambda: sorted(zzz())


def lcd(xnum1, xnum2): return (xnum1*xnum2//gcd(xnum1, xnum2))
def output(answer): stdout.write(str(answer))


###########################---Test-Case---#################################
"""

  If you Know me , Then you probably don't know me !


"""
###########################---START-CODING---##############################

x1,y1,x2,y2=zzz()


king=max(abs(x1-x2),abs(y1-y2)) 
boat= 1 if x1==x2 or y1==y2 else 2
if (x1+y1)%2!=(x2+y2)%2:
    hati=0
if x1-y1==x2-y2 or  x1+y1==x2+y2 :
    hati=1
else:
    hati=2
print(boat,hati,king)
        

    
