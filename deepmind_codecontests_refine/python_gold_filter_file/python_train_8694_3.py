import os, sys, pdb
import time, calendar, datetime
import math, itertools
import operator as op
from functools import reduce

def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer // denom

a,b,c = list(map(int, input().split()))
x1 = ( (-b + math.sqrt(b*b-4*a*c))/(2*a) )
x2 = ( (-b - math.sqrt(b*b-4*a*c))/(2*a) )

print(max(x1,x2))
print(min(x1,x2))

