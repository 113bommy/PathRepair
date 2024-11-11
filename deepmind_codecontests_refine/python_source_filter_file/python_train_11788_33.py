from __future__ import division, print_function
 
import os,sys
from io import BytesIO, IOBase
 
if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip
 
 
def ii(): return int(input())
def si(): return input()
def mi(): return map(int,input().split())
def li(): return list(mi())

for i in range(ii()):
    s=si()
    c=0 
    l=[]
    if s.count('1')==0:
        print(0)
        continue
    for i in range(len(s)):
        if s[i]=='1':
            l.append(i)
            
    if len(l)==1:
        print(0)
        continue
            
    l1=[]
    for i in range(1,len(l)):
        l1.append(l[i]-l[i-1]) 
        
    print(max(l1)-1)