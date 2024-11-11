def nibutan(L):
  ok = len(L)
  ng = -1
  while abs(ok - ng) > 1:
    mid = (ok + ng) // 2
    if nasu(mid, L):
      ok = mid
    else:
      ng = mid
  return ok

def nasu(n, L):
  p = L[n] + M
  if p < L[K]:
    return False
  m = (V - 1 - (n + P - 1)) * M
  if m <= 0:
    return True
  for i in range(n + 1, K + 1):
    m -= p - L[i]
    if m <= 0:
      return True
  return False

N, M, V, P = list(map(int, input().split()))
A = list(map(int, input().split()))

A.sort()
K = N - P
T = A[K]
print(N - nibutan(A))