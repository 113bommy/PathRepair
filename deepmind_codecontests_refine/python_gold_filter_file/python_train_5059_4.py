p, x, y = map(int, input().split())
z = (x - y) // 50
d = x // 50 - z
n = 1 - z
while 1:
    i = d % 475
    for j in range(25):
        i = (i * 96 + 42) % 475
        if i == p - 26:
            print((n > 0) * n // 2)
            exit()
    n += 1
    d += 1