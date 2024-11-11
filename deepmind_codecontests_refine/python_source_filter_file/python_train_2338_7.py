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
        n=num()
        a=nums()
        jml=sum(a)
        if jml%3!=0:
            return 0
        ptri=jml//3
        mult=0
        ans=0
        if a[0]==ptri:
            mult=1
        #perr("ptri",ptri)
        for ii in range(1,n):
            #perr("ii",ii)
            a[ii]+=a[ii-1]
            #perr("cursum",a[ii])
            #perr("mult",mult)
            if a[ii]==2*ptri:
                ans+=mult
            if a[ii]==ptri:
                mult+=1
        return ans
    print(solve())
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