t = int(input())
for _ in range(t):
    n, x, y, d = map(int, input().split())
    x, y = x - 1, y - 1
    if x < y and (y - x) % d == 0:
        print((y - x) // d)
        continue
    if y < x and (x - y) % d == 0:
        print((x - y) // d)
        continue
    if y % d == 0 and (n - 1 - y) % d == 0:
        print(min((x + y + d - 1) // d, (n - 1 - y + d - 1) // d + (n - 1 - x + d - 1) // d))
        continue
    if y % d == 0:
        print((x + y + d - 1) // d)
        continue
    if (n - 1 - y) % d == 0:
        print((n - 1 - y + d - 1) // d + (n - 1 - x + d - 1) // d)
        continue
    print(-1)
