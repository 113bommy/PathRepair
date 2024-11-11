n = int(input())
for _ in range(n):
    x, y, x1, y1 = map(int, input().split())
    if x == x1 or y == y1:
        print(1)
    else:
        print(abs(x - x1) + abs(y - y1))