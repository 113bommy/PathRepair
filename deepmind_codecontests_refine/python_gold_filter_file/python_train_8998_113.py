#-------------------------------------------------------------------------------
# Name:        Codeforces
# Author:      GogolGrind
#-------------------------------------------------------------------------------
import sys
from math import *

def solve():
    s = str(input())
    x = 0
    if (len(s) > 1):
        x = 10*int(s[-2]) + int(s[-1])
    else:
        x = int(s[0])
    if (x % 4):
        print(0)
    else:
        print(4)
    
solve()
