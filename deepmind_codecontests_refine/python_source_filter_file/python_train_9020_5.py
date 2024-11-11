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

n=ri()
a=ris()

mp=ddict(int)
best=0
for i in range(n-1,-1,-1):
  x=a[i]
  mp[x]=max(mp[x],1+mp[x+1])
  if mp[x]<=mp[a[best]]:
    best=i
  
i=j=best
k=mp[a[i]]-1
ans=[i+1]
while k>0:
  if a[i]==a[j]-1:
    ans.append(j+1)
    k-=1
    i=j
  j+=1

print(len(ans))
print(*ans)
