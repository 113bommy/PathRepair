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

n, = list(map(int, input().split()))
print(2**(n+1) - 2)


