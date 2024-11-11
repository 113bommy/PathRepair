import math

n,m,z = list(map(int, input().split()))
k = 0
g = math.gcd(n, m)
if n == 1:
    g = m
if m == 1:
    g = n
print(z // g)
