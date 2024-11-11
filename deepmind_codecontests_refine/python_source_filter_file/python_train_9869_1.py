def gcd(x, y):
    while y:
        x, y = y, x % y
    return x


a, b = [int(x) for x in input().split(' ')]

g = gcd(a, b)
ret: int = 1
i = 2
while i * i <= g:
    if g % i == 0:
        while g % i == 0:
            g /= i
        ret += 1
    i += 1

if g > 1:
    ret += 1

print(ret)