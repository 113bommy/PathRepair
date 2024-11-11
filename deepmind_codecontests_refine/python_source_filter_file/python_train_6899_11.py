import sys
input=sys.stdin.readline
from collections import defaultdict as dc
from bisect import bisect_right
s=input()[:-1]
n=len(s)
print('R',n-1)
print('L',n)
print('L',2)