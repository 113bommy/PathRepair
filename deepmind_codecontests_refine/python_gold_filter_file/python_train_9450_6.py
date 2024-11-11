import sys
readline = sys.stdin.readline

N,K = map(int,readline().split())
A = [0] + list(map(int,readline().split()))

c = 1
while K:
  if K&1:
    c = A[c]
  na = [0] * (N+1)
  for i in range(N+1):
    na[i] = A[A[i]]
  na,A = A,na
  K >>= 1
print(c)