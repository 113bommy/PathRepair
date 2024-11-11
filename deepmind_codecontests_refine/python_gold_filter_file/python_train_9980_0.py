from sys import exit, setrecursionlimit
from functools import reduce
from itertools import *
from collections import defaultdict

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

setrecursionlimit(1000000)

(R, C) = reads()
N = read()

d = defaultdict(list)
V = set()

for _ in range(N):
  (r, c, a) = reads()
  (r, c) = (r-1, c-1)
  d["R", r].append((("C", c), a))
  d["C", c].append((("R", r), a))
  V.add(("R", r))
  V.add(("C", c))

def walk(v):
  V.discard(v)
  for (w, a) in d[v]:
    wcol = a - col[v]
    if w in col:
      if col[w] != wcol:
        print("No"); exit()
    else:
      col[w] = wcol
      walk(w)

while len(V) > 0:
  v = V.pop()
  col = dict()
  col[v] = 0
  walk(v)
  rcol = min(a for (v, a) in col.items() if v[0] == "R")
  ccol = min(a for (v, a) in col.items() if v[0] == "C")
  if rcol + ccol < 0:
    print("No"); exit()

print("Yes")
