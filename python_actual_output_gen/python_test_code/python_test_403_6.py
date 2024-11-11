n = int(input())
for _ in range(n):
    x, y, a, b = map(int, input().split())
    if (y - x) % (a + b) == 0:
        print((x - y) // (a + b))
    else:
        print(-1)