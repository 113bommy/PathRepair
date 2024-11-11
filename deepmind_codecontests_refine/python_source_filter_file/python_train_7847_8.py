k = 0
x, y, m = map(int, input().split())
if (y < x):
    x, y = y, x
if (y > m):
    print(0)
else:
    if (x <= 0) and (y <= 0):
        print(-1)
    else:
        if (x <= 0) and (y > 0):
            if (abs(x) % y > 0):
                k += abs(x) // y + 1
            else:
                k += abs(x) // y
            x = x + y * k
        a = 0
        b = 1
        c = 0
        while (c < 5000000000000000000):
            if (a * x + b * y >= m):
                print(k)
                break
            c = a + b
            a = b
            b = c
            k += 1
        if (c >= 5000000000000000000):
            print(-1)