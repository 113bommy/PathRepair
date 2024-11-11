import math
import fractions
n = int(input())
a_ls = list(map(int,input().split()))
lcm = 1
ans = 0
mod = 10**9+7
for i in a_ls:
    lcm = lcm * i//fractions.gcd(lcm,i)
for i in a_ls:
    ans += lcm//i
print(ans%mod)
