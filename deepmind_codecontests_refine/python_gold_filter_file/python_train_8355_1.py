t = int(input())

for i in range(t):
    n, x, y = tuple(map(int, input().split()))
    space = y - x
    for gap in range(1, space + 1):
        if space % gap == 0 and gap * (n - 1) >= space:
            break

    if y - gap * (n - 1) > 0:
        print(*[y - i * gap for i in range(n)])
    else:
        start = x % gap
        if start == 0:
            start += gap
        print(*[start + i * gap for i in range(n)])
