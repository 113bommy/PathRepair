# import sys
# input = lambda: sys.stdin.readline().rstrip()
import sys
import math
input = sys.stdin.readline
from collections import deque
from queue import LifoQueue

def binary_search(a, n):
  L = 0
  R = len(a)-1
  while L<=R:
    mid = L+(R-L)//2
    if a[mid]==n:
      return mid
    elif a[mid]<n:
      L = mid+1
    else:
      R = mid-1
  return -1

for _ in range(int(input())):
  n,m,k = map(int, input().split())
  maxi = n//k
  if maxi>=m:
    print(m)

  else:
    rem = m-maxi
    if rem%(n-1)==0:
      print(maxi-(rem//(k-1)))
    else:
      print(maxi-(rem//(k-1))-1)