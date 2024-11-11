import sys
import collections
import math
import functools
import itertools
import bisect
import operator
import heapq
import random
true=True
false=False
null=None
tcid=0
tcmax=99999999
def compute(val, func): return func(val)
def seq(lo,hi,step=1): 
 return range(lo,hi+1,step)
def sround(val,nd):
 return f'{val:.{nd}f}'
def ceil(a,b):
 ans=a//b
 if a%b!=0: ans+=1
 return ans
def perr(*args,**kwargs): print(*args,file=sys.stderr,**kwargs)
def line():
 ln=sys.stdin.readline().strip()
 #perr(ln)
 if ln=='': sys.exit()
 return ln
def lines(n): return [line() for i in range(n)]
def split(ln=None): return (ln or line()).split()
def num(str=None):
 str=str or line()
 return float(str) if '.' in str else int(str)
def nums(o=None):
 if o is not None:
  if isinstance(o, int): o=lines(o)
  elif isinstance(o, str): o=split(o)
 return list(map(num, o or split()))
#
#help("sys.modules")
"""
ceil(a,b) sround(val,nd) true false null
num(?) nums(?) split(?) lines(n) line()
perr(print) tcmax seq() compute(v,f) tcid
"""
#{#

#}#
def mainloop(tcid=1):
# {{{
 def solve():
  n=[0,0]
  for dd in line():
   n.append(int(dd))
  for ii in range(len(n)-2):
   for jj in range(ii+1,len(n)-1):
    for kk in range(ii+2,len(n)):
     bb=n[ii]*100+n[jj]*10+n[kk]
     if bb%8==0:
      return bb
 ans=solve()
 if ans is null:
  print("NO")
 else:
  print("YES")
  print(ans)
# }}}
while tcid<tcmax:
 tcid+=1
 mainloop(tcid)
"""
NOTES = .

"""
"""
PROBLEM #ID = .

"""