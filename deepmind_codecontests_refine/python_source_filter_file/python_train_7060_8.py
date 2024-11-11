from itertools import accumulate
from bisect import bisect

N = int(input())
C = [0]+list(accumulate(map(int,input().split())))

def h(i,j):
  ci,cj = C[i],C[j]
  k = bisect(C, (ci+cj)//2, lo=i+1,hi=j)
  _,a,b = min((abs(ci+cj-2*c),cj-c,c-ci) for c in (C[k-1],C[k]))
  return a,b

def solve(x):
  L = h(0,x)+h(x,N)
  return max(L)-min(L)

print(min(solve(i) for i in range(2,N-2)))