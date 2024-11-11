import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
#from bisect import bisect_left as bl, bisect_right as br, insort
#from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
#from itertools import permutations,combinations
def data(): return sys.stdin.buffer.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def out(var) : sys.stdout.write(str(var)+'\n')
#from decimal import Decimal
#from fractions import Fraction
#sys.setrecursionlimit(100000)
#INF = float('inf')
mod = int(1e9)+7



a,b,k=mdata()
if k>max(a+b-2,0) or (b==1 and k) or (a==0 and k):
    out("NO")
else:
    out("YES")
    if k==0:
        out('1'*b+'0'*a)
        out('1'*b+'0'*a)
    else:
        s1='0'*min(k,a)
        s2='1'+'0'*(min(k,a)-1)
        a,k=a-min(a,k),k-min(a,k)
        s1+='1'*(b-1) + '0'*a + '1'
        s2+='1'*(k) + '0' + '1'*(b-k-2) + '0'*a + '1'
        s1=s1[::-1]
        s2=s2[::-1]
        out(s1)
        out(s2)



