for _ in range(int(input())):

    x, y, c = map(int, input().split())

    if x + y - min(x, y) > c: print(-1)
    else:
        if c%2: print(c - (c-x)%2 - (c-y)%2)
