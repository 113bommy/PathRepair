#      Codeforces Round #491 (Div. 2)
import collections
from functools import cmp_to_key
#key=cmp_to_key(lambda x,y: 1 if x not in y else -1 )
import math
import sys
def getIntList():
    return list(map(int, input().split()))    

import bisect 
try :
    import numpy
    dprint = print
    dprint('debug mode')
except ModuleNotFoundError:
    def dprint(*args, **kwargs):
        pass
def makePair(z):
    return  [(z[i], z[i+1]) for i in range(0,len(z),2) ]


 
A,B,C,N  = getIntList()

if A<C or B<C:
    print(-1)
    sys.exit()
z = A+B - C

if z+1>= N:
    print(-1)
    sys.exit()

print(N-z)

        
