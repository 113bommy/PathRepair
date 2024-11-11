N, X = map(int, input().split())

def burger(N,X):
  print(N,X)
  if N == 0 and X == 1:
    return 1
  if X == 0:
    return 0
  twopow = pow(2,N)
  if X == 4*twopow-3:
    return 2*twopow-1
  if X > 2*twopow-2:
    return twopow + burger(N-1,X-2*twopow+1)
  elif X <= 2*twopow-2:
    return burger(N-1,X-1)

print(burger(N,X))
