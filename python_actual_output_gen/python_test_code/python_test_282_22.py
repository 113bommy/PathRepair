N, X = (int(i) for i in input().split())  
L = [1]
P = [1]

for _ in range(N):
  L.append(L[-1] * 2 + 3)
  P.append(P[-1] * 2 + 1)

def count(x,n):
  if n == 0:
    return 0 if x <= 0 else 1
  elif x <= L[n-1] + 2:
    return count(x-1, n-1)
  else:
    return P[n-1] + 1 + count(x-(L[n-1]+2),n-1)

#print(L,P)
print(count(X, N))