from sys import exit, setrecursionlimit, stderr
from functools import reduce
from itertools import *
from collections import *
from bisect import *

def read():
  return int(input())
 
def reads():
  return [int(x) for x in input().split()]

setrecursionlimit(1 << 30)

N = read()
edges = [[] for _ in range(N)]
for _ in range(N-1):
  a, b = reads()
  a, b = a-1, b-1
  edges[a].append(b)
  edges[b].append(a)

def dist(u, d):
  for v in edges[u]:
    if d[v] >= 0:
      continue
    d[v] = d[u] + 1
    dist(v, d)
  return d

distf = dist(0, [0]+[-1]*(N-1))
dists = dist(N-1, [-1]*(N-1)+[0])

numf = sum(distf[i] <= dists[i] for i in range(N))
nums = N - numf

if numf >= nums:
  print("Fennec")
else:
  print("Snuke")