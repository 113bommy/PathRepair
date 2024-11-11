a1, b1, c1 = map(int, input().split())
a2, b2, c2 = map(int, input().split())

if a1 * b2 - a2 * b1 != 0: print(1)
else:
    ca = c1 * a2 - c2 * a1
    bc = b1 * c2 - b2 * c1

    if ca != 0 and bc != 0: print(0)
    elif a2 == 0 and b2 == 0 and c2 != 0: print(0)
    elif a1 == 0 and b1 == 0 and c1 != 0: print(0)
    else: print(-1)
