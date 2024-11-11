from math import gcd

n = int(input())
ans = 1
for _ in range(n):
    t = int(input())
    ans = ans * t // gcd(ans, t)
print(ans)