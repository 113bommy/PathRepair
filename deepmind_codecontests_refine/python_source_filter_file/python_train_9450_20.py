N, K = map(int, input().split())
A = tuple( map(int, input().split()) )

L = [0 for i in range(N+1)]
L[1] = 1
x = 1
t = 1
while K>0:
  t += 1
  K -= 1
  x = A[x]
  if L[x] != 0:
    p = t - L[x]
    K %= p
    break
  else:
    L[x] = t
    
while K>0:
  x = A[x]
  K -= 1
print(x)