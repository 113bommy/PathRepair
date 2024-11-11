N,K,Q = map(int, input().split())
A = [-K] * N
for _ in range(Q):
  A[int(input())-1] += 1
for n in range(N):
  if A[n] > 0: print("Yes")
  else: print("No")