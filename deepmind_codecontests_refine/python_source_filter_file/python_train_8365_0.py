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

pos={}
pts={}
t=ri()
for _ in range(t):
  n=ri()
  for i in range(n):
    s=rl()
    if s not in pos:
      pos[s]=[0]*50
      pts[s]=0
    pos[s][i]-=1
    if i<10:
      pts[s]-=[25, 18, 15, 12, 10, 8, 6, 4, 2, 1][i]

by_pts=sorted(pts,key=lambda x:(pts[x],pos[x]))[0]
by_pos=sorted(pts,key=lambda x:(pos[x][0],pts[x]))[0]
print(by_pts)
print(by_pos)
