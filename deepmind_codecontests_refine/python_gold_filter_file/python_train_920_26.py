from sys import exit, setrecursionlimit, stderr
from functools import reduce
from itertools import *
from collections import defaultdict
from bisect import bisect
from random import *

def read():
  return int(input())
 
def reads():
  return [int(x) for x in input().split()]

N, x = reads()
A = reads()

INF = 1 << 60
smin = [[INF] * N for _ in range(N)]
for i in range(N):
  smin[i][0] = A[i]
  for j in range(1, N):
    smin[i][j] = min(smin[i][j-1], A[(i-j)%N])

ans = INF
for j in range(N):
  h = sum(smin[i][j] for i in range(N)) + x * j
  ans = min(ans, h)
print(ans)
