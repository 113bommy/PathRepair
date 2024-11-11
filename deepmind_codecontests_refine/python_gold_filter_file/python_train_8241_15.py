import sys, itertools, math

def ia():
  return [int(i) for i in sys.stdin.readline().strip().split(" ")]

def ii():
  return int(sys.stdin.readline().strip())

def istr():
  return sys.stdin.readline().strip()

###

for _ in range(ii()):
  n, m = ia()
  D = []
  for i in range(100022222200):
    p = i * m
    if i > 0 and p % 10 == 0:
      break
    D.append(p%10)

  rep = n//len(D)//m
  ans = sum(D)*rep

  for i in range(rep*len(D), n+1):
    p = i * m
    if p > n:
      break
    ans += p % 10

  print(ans)

