from fractions import gcd

MOD = 10**9 + 7
N = int(input())
A = list(map(int, input().split()))

l = A[0]
for a in A:
  l = l * a // gcd(l, a)

ans = 0
for a in A:
  ans += (l//a)

print(ans%MOD)