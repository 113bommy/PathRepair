from collections import deque

N, X, M = map(int, input().split())

D = deque([X], M)
R = {X: 0}

x = X
for _ in range(min(N-1, M+1)):
  x = (x ** 2) % M
  if x in R:
    l = R[x]
    m = len(D) - l
    q, r = divmod(N - l, m)
    print(sum(D[i] for i in range(l)) + (q+1) * sum(D[i] for i in range(l, l+r)) + q * sum(D[i] for i in range(l+r, l+m)))
    break
  else:
    R[x] = len(D)
    D.append(x)
else:
  print(sum(D))
print(D)