import re
import sys
exit=sys.exit
from bisect import bisect_left as bsl,bisect_right as bsr
from collections import Counter,defaultdict as ddict,deque
from functools import lru_cache
cache=lru_cache(None)
from heapq import *
from itertools import *
from math import inf
from pprint import pprint as pp
enum=enumerate
ri=lambda:int(rln())
ris=lambda:list(map(int,rfs()))
rln=sys.stdin.readline
rl=lambda:rln().rstrip('\n')
rfs=lambda:rln().split()
cat=''.join
catn='\n'.join
mod=1000000007
d4=[(0,-1),(1,0),(0,1),(-1,0)]
d8=[(-1,-1),(0,-1),(1,-1),(-1,0),(1,0),(-1,1),(0,1),(1,1)]
########################################################################

def solve():
  n,s=ris()
  ans=0
  k=1+n//2
  lo,hi=0,s
  while lo<=hi:
    mid=lo+hi>>1
    if k*mid<=s:
      ans=mid
    if k*mid<s:
      lo=mid+1
    else:
      hi=mid-1
  return ans

t=ri()
for _ in range(t):
  print(solve())
