from math import gcd

N = int(input())
A = list(map(int, input().split()))
MOD = 10**9 + 7

lcm = 1
for a in A:
    lcm = lcm * a // gcd(lcm, a)


ans = 0
for a in A:
    ans += lcm // a


print(ans % MOD)