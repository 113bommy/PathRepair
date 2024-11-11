def ints():
  return [int(x) for x in input().split()]
def ii():
  return int(input())

N, M = ints()
A = ints()
A.sort()

def combinations(x):
  s = 0
  i = 0
  j = N-1
  while j>=0:
    while i<N and A[i]+A[j]<x:
      i += 1
    s += N-i

    j -= 1
    
  return s

def koufukudo(x):
  s = 0
  si = 0
  j = 0
  i = N-1
  while j<N:
    while i>=0 and A[i]+A[j]>=x:
      si += A[i]
      i -= 1
    s += si + A[j]*(N-1-i)

    j += 1
    
  return s


def bsearch(lower, upper):
  l = lower
  u = upper
  m = (l+u)//2
  c = combinations(m)
  if c<M:
    return bsearch(l, m)
  else:
    if l==m:
      return (l, c-M)
    return bsearch(m, u)

x, dm = bsearch(0, A[-1]*2+1)
print(x)
print(koufukudo(x)-dm*x)
