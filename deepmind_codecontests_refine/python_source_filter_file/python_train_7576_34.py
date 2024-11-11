
from fractions import gcd

N = int(input())
A = list(map(int, input().split()))
mod = 10**9 + 7

x = 1
for i in range(N):
  x = (x*A[i]) // gcd(x, A[i])

ans = 0
for a in A:
  ans += x//a
  ans %= mod
print(ans)
