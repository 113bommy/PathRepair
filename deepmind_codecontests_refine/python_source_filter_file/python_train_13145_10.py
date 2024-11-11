T = int(input())

for t in range(T):
    X, Y = [int(_) for _ in input().split()]
    C = [int(_) for _ in input().split()]

    for _ in range(10):
        for i in range(len(C)):
            prev = i-1
            if prev < 0:
                prev += 6
            nxt = i+1
            if nxt >= 6:
                nxt -= 6
            C[i] = min(C[i], C[prev]+C[nxt])
        for i in range(len(C)-1, -1, -1):
            prev = i-1
            if prev < 0:
                prev += 6
            nxt = i+1
            if nxt >= 6:
                nxt -= 6
            C[i] = min(C[i], C[prev]+C[nxt])

    c1, c2, c3, c4, c5, c6 = C[0], C[1], C[2], C[3], C[4], C[5]

    if X == 0:
        if Y > 0:
            print(c2 * Y)
        else:
            print(c5 * Y)
    elif X < 0:
        if Y >= 0:
            print(c3 * abs(X) + c2 * Y)
        elif Y <= X:
            print(c4 * abs(X) + c5 * abs(X-Y))
        else:
            print(c3 * abs(X-Y) + c4 * abs(Y))
    elif X > 0:
        if Y >= X:
            print(c1 * X + (Y-X) * c2)
        elif Y <= 0:
            print(c6 * X + abs(Y) * c5)
        else:
            print(c1 * Y + c6 * (X-Y))
