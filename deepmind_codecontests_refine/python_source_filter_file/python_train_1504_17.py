import sys, itertools, math, collections, random

def ia():
  return [int(i) for i in sys.stdin.readline().strip().split(" ")]

def ii():
  return int(sys.stdin.readline().strip())

def istr():
  return sys.stdin.readline().strip()

###

OPS = [">", "<", "<=", ">="]

nmin = -10**10
nmax = 10**10
for _ in range(ii()):
  op, n, t = istr().split(" ")
  n = int(n)

  if t == "N":
    op = OPS[(OPS.index(op) + 2)%4]

  if op == ">":
    nmin = max(n+1, nmin)
  elif op == ">=":
    nmin = max(n, nmin)
  elif op == "<":
    nmax = min(n-1, nmax)
  elif op == "<=":
    nmax = min(n, nmax)

if nmax < nmin:
  print("Impossible")
else:
  print(nmin)