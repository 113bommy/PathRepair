n, x = map(int, input().split())

d = 0
for _ in range(n):
    s, p = input().split()

    if s == '+':
        x += int(p)
    else:
        if x - int(p) > 0:
            x -= int(p)
        else:
            d += 1

print(x, d)