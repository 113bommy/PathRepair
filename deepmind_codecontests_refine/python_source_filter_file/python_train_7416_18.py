from __future__ import division, print_function
import sys
if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip

import os, sys, bisect, copy
from collections import defaultdict, Counter, deque
#from functools import lru_cache   #use @lru_cache(None)
if os.path.exists('in.txt'): sys.stdin=open('in.txt','r')
if os.path.exists('out.txt'): sys.stdout=open('out.txt', 'w')
#
def input(): return sys.stdin.readline()
def mapi(arg=0): return map(int if arg==0 else str,input().split())
#------------------------------------------------------------------


tmp =[]
i = 2
j = 2
while i<int(1e9):
    tmp.append(i)
    j+=2
    i+=j+j//2-1
print(tmp[:10])
for _ in range(int(input())):
    n = int(input())
    m = len(tmp)
    res = 0
    while n>1:
        x = tmp[bisect.bisect_right(tmp,n)-1]
        #print(x)
        res+=1
        n-=x
    print(res)

