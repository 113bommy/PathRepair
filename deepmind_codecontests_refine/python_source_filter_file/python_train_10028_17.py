import sys
import math
from collections import deque,Counter
#sys.setrecursionlimit(10**7)
int1=lambda x: int(x)-1

inp=lambda :int(input())
mi=lambda :map(int,input().split())
li=lambda :list(mi())
mi1=lambda :map(int1,input().split())
li1=lambda :list(mi1())
mis=lambda :map(str,input().split())
lis=lambda :list(mis())
pr=print

from collections import defaultdict
"""
#初期値 0
d=defaultdict(int)

#初期値 1
d=defaultdict(lambda:1)
"""

mod=10**9+7
Mod=998244353
INF=10**18
ans=0

t=inp()
for _ in range(t):
  n=inp()
  x=(math.sqrt(n)-0.01)
  if int(x)**2==n:
    print(int(x))
  else:
    print(int(x)+1)