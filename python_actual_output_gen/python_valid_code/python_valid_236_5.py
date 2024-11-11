for _ in range(int(input())):
    n, x, y = map(int, input().split())
    if x > y:
        x, y = y, x
    minx = max(1, x + y + 1 - n)
    mn = minx
    mx = min(n, x + y - 1)
    print(mn, mx)
