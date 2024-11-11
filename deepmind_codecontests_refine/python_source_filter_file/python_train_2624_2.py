for _ in range(int(input())):
    x, y = map(int, input().split())
    if y % x == 0:
        print((y // x) ** 2 * x)
    else:
        mx = y // x + 1
        col = (y - y // x) // mx
        ost = y - mx * col
        print(col * (mx ** 2) + ost * (y // x))
