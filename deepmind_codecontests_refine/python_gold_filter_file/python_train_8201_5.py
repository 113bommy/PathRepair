import math

N = int(input())
A = list(map(int, input().split()))

def honya(n, L):
  k = 0
  E = len(L)
  for i in range(n - 1, -1, -1):
    for j in range(k, E):
      if (L[j] >> i) & 1:
        L[k], L[j] = L[j], L[k]
        break
    else:
      continue
    k += 1
    for j in range(k, E):
      if (L[j] >> i) & 1:
        L[j] ^= L[k - 1]
  return L

def nasu(n):
  return math.ceil(math.log(n + 1, 2))

A.sort(reverse = True)
M = nasu(A[0])
P = [1]
for i in range(M):
  P.append(P[-1] * 2)

D = [0] * M
for i in range(N):
  t = A[i]
  for j in range(M):
    if t & 1:
      D[j] += 1
    t >>= 1

ans = 0
for i in range(M - 1, -1, -1):
  if D[i] % 2 == 1:
    ans += P[i]
    for j in range(N):
      A[j] &= ~(1 << i)

L = honya(M, A)
t = 0
for i in range(N):
  if L[i] == 0: break
  if (t & (1 << (nasu(L[i]) - 1))) == 0:
    t ^= L[i]

for i in  range(M - 1, -1, -1):
  if (t >> i) & 1:
    ans += P[i] * 2
    
print(ans)
