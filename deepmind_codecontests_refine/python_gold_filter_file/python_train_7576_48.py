from fractions import gcd
N = int(input())
A = [int(i) for i in input().split()]
lcm = A[0]
MOD = 10**9 + 7
for a in A:
    lcm = (lcm // gcd(lcm,a) * a)
res = 0
for a in A:
    res += lcm //a
print(res % MOD)
