import math
n,m,z = list(map(int, input().split()))
g = (n*m) // math.gcd(n, m)
if n == 1:
    g = m
if m == 1:
    g = n
print(z // g)
