from math import gcd

n, k = map(int, input().split())
a, b = map(int, input().split())
tot = n*k

mn, mx = 100000, 0

for ai in a, -a:
    for ni in range(n):
        for bi in b, -b:
            pos1 = ai
            pos2 = k*ni + bi
            if pos1 == pos2:
                x = 1
            else:
                x = tot // gcd(tot, abs(pos1 - pos2))
            mn = min(mn, x)
            mx = max(mx, x)

print(mn, mx)