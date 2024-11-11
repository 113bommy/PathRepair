import sys
input=sys.stdin.buffer.readline
inin=lambda: int(input())
inar=lambda: list(map(int,input().split()))
inst=lambda: input().decode().rstrip('\n\r')
# INF=float('inf'); from math import gcd 
from collections import deque as que, defaultdict as vector, Counter
# from bisect import bisect
# from heapq import heapify, heappush as hpush, heappop as hpop
'''from types import GeneratorType
def recursive(f, stack=[]):
  def wrappedfunc(*args, **kwargs):
    if stack: return f(*args, **kwargs)
    else: 
      to = f(*args, **kwargs)
      while True:
        if type(to) is GeneratorType:
          stack.append(to); to = next(to)
        else:
          stack.pop()
          if not stack: break
          to = stack[-1].send(to)
      return to
  return wrappedfunc'''

_T_=inin()
for _t_ in range(_T_):
    n=inin()
    ma=vector(int)
    for i in range(n):
        s=inst()
        for j in s:
            ma[j]+=1
    for i in ma:
        if ma[i]%2==1:
            print('NO')
            break
    else:
        print('YES')

