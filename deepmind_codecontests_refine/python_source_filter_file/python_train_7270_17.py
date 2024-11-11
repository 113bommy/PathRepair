from math import gcd

n = int(input())

ans = 1
for _ in range(n):
    x = int(input())
    ans = ans * x // gcd(ans, x)

print(ans)
