# from math import gcd
from fractions import gcd

n = int(input())
a = list(map(int,input().split()))
ans = 1
for i in a:
    ans = ans * i // gcd(ans, i)
mod = 10**9+7
print(sum(map(lambda x: ans // x, a)) % mod)
