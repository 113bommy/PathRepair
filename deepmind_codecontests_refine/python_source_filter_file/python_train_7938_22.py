n, m, x, y = map(int, input().split())
b = 0
x0 = x
y0 = y
for i in range(m * n):
    print(x, y)
    if b == 0:
        y -= 1
        if y == 0:
            y = y0 + 1
            b = 1
    elif b == 1:
        y += 1
        if y == m + 1:
            x -= 1
            y = m
            b = 2
    elif b == 2:
        y -= 1
        if y == 0:
            y = 1
            x -= 1
            if x == 0:
                x = x0 + 1
                b = 5
            else:
                b = 3
    elif b == 3:
        y += 1
        if y == m + 1:
            y = m
            x -= 1
            if x == 0:
                x = x0 + 1
                b = 4
            else:
                b = 2
    elif b == 4:
        y -= 1
        if y == 0:
            y = 1
            x += 1
            b = 5
    else:
        y += 1
        if y == m + 1:
            y = m
            x -= 1
            b = 4
