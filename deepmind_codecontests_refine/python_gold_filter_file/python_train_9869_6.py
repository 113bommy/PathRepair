from fractions import gcd
d = gcd(*map(int, input().split()))
r = 1
i = 2
while i * i <= d:
    r += d % i == 0
    while d % i == 0:
        d //= i
    i += 1
print(r + (d > 1))