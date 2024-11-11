for _ in range(int(input())):

    x, y, c = map(int, input().split())

    if x + y - min(x, y) > c: print(-1)
    else:
        print(c - (c-x)%2 - (c-y)%2)
