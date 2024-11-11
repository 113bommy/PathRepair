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
mod=1000000007
d4=[(0,-1),(1,0),(0,1),(-1,0)]
d8=[(-1,-1),(0,-1),(1,-1),(-1,0),(1,0),(-1,1),(0,1),(1,1)]
########################################################################

n,m=ris()
a=[]
s=0
for _ in range(n):
  x,y=ris()
  a.append((x,y))
  s+=y

if s>m:
  print(-1)
  exit()

a.sort(key=lambda x:x[0]-x[1])

ans=0
for x,y in a:
  s-=y
  s+=x
  if s>m:
    break
  ans+=1

print(ans)
