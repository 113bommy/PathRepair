N = int(input())
A = list(map(int,input().split()))
from fractions import gcd
mod = 10**9+7
g = A[0]
for a in A[1::]:
  g = g*a//gcd(g,a)
  
ans = 0
b = g%mod
for a in A:
  ans += g%mod*pow(a,mod-2,mod)
  ans %= mod
  
print(ans%mod)
