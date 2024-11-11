import sys
readline = sys.stdin.readline
N,K = map(int,readline().split())
A = [0] + list(map(int,readline().split()))
c = 1
while K:
  if K & 1:
    c = A[c]
  A = [A[i] for i in range(len(A))]
  K >>= 1
print(c)