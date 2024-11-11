from fractions import gcd
 
d = gcd(*map(int, input().split()))
r = 1
i = 2
while i * i <= d:
    c = 0
    while d % i == 0:
        c += 1
        d //= i
    r += c > 0
    i += 1
print(r + (d > 1))