from itertools import permutations
#from fractions import Fraction
from collections import defaultdict
from math import*
import os
import sys
from io import BytesIO, IOBase
from heapq import nlargest
from bisect import*
import copy
import itertools

t=int(input())
while t:
    t-=1
    x1,y1,x2,y2=map(int,input().split())
    val1=fabs(y1-y2)
    val2=fabs(x1-x2)
    ans=val2+val1
    if val2==0 or val1==0:
        print(ans)
    else:
        print(ans+2)