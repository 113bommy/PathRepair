n = int(input())
a = list(map(int, input().split()))

lcm = 1
from fractions import gcd
for i in range(n):
    lcm *= a[i] // gcd(a[i], lcm)

ans = 0
for i in a:
    ans += lcm // i

print(ans % (10**9+7))