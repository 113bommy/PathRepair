import sys
readline = sys.stdin.readline

N,K = map(int,readline().split())
A = [0] + list(map(int,readline().split()))

now = 1
while K > 0:
  if K & 1:
    now = A[now]
  A = [A[A[i]] for i in range(len(A))]
  K >>= 1

print(now)