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
#scan integer
import gc, os
ii,_inp =0, b''
#fd = os.open("in.txt", os.O_RDONLY)
def getchar():
    global ii, _inp
    if ii >= len(_inp):
        _inp = os.read(0, 50000)
        #_inp = os.read(fd, 50000)
        gc.collect(); ii = 0
    if not _inp: return b' '[0]
    ii += 1
    return _inp[ii - 1]
def intut():
    c = getchar()
    if c == b'-'[0]: x = 0; sign = 1
    else: x = c - b'0'[0]; sign = 0
    c = getchar()
    while c >= b'0'[0]: x = 10*x + c - b'0'[0]; c=getchar()
    if c == b'\r'[0]: getchar()
    return -x if sign else x
#def input(): return sys.stdin.readline()
def mapi(arg=0): return map(int if arg==0 else str,input().split())
#------------------------------------------------------------------

n = intut()
q = intut()
mx = n+1
bit = [0]*(mx)
def update(idx,val):
    while idx<n:
        bit[idx]+=val
        #idx+=idx&(-idx)
        idx|=idx+1

def query(x):
    idx = -1
    m = n.bit_length()
    for i in range(m-1,-1,-1):
        rightIdx = idx+(1<<i)
        if rightIdx<n and x>=bit[rightIdx]:
            idx = rightIdx
            x-=bit[idx]
    return idx+1
for i in range(n):
    x = intut()
    update(x-1,1)
for i in range(q):
    x = intut()
    ans = x-1
    val = 1
    if x<0:
        val = -1
        ans = query(-x-1)
        #while r-l>=0:
        #    mid = (l+r)>>1
        #    #print("YES")
        #    if query(mid)>=-x:
        #        ans = mid
        #        r = mid-1
        #    else:
        #        l = mid+1
    update(ans,-1)
res = 0
for i in range(n):
    if bit[i]>0:
        res = i+1
        break
print(res)
#os.close(fd)
