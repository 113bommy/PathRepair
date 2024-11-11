p, d = input().split()
p = int(p); d = int(d)

ans = p = p + 1
i = 10

while i <= 1000000000000000000:
    if p % i <= d:
        ans = p - p % i
    i *= 10

print(ans - 1)