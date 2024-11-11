from fractions import gcd
mod = 10**9+7
n = int(input())
A = list(map(int, input().split()))
m = A[0]
for i in range(1, n):
  m = A[i] // gcd(m, A[i]) * m
ans = 0
for i in A:
  ans += m//i
print(ans%mod)