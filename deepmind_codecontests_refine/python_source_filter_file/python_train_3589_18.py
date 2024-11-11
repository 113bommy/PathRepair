import os, sys, bisect, copy
from collections import defaultdict, Counter, deque
from functools import lru_cache   #use @lru_cache(None)
if os.path.exists('in.txt'): sys.stdin=open('in.txt','r')
if os.path.exists('out.txt'): sys.stdout=open('out.txt', 'w')
#
def input(): return sys.stdin.readline()
def mapi(arg=0): return map(int if arg==0 else str,input().split())
#------------------------------------------------------------------

n,m = mapi()
ah = [0]*n
bh = [0]*m
a = list(mapi())
b = list(mapi())
for i in a[1:]:
    ah[i]=1
for i in b[1:]:
    bh[i]=1
for i in range(m*n):
    if ah[i%n]==1 or bh[i%m]==1:
        ah[i%n] = 1
        bh[i%m] = 1
flag = 1
for i in ah:
    if i==0:
        flag = 0
        break
for i in bh:
    if i==0:
        flag = 0
        break
if flag:
    print("Yes")
else:
    print("No")
