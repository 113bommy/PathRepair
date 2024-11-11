from fractions import gcd
N = int(input())
A = list(map(int, input().split()))

L = [0]*(N+2)
R = [0]*(N+2)
for i in range(N):
  L[i+1] = gcd(L[i], A[i])
for i in range(N, 0, -1):
  R[i] = gcd(R[i+1], A[i-1])
ans = 0
for i in range(1, N):
  ans = max(ans, gcd(L[i-1], R[i+1]))
print(ans)