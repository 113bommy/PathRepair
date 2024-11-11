t = int(input())
for i in range(0, t):
    a, b, c, d = map(int, input().split(" "))
    x, y, x1, y1, x2, y2 = map(int, input().split(" "))
    if (
        (x1 <= x + (b - a) <= x2)
        and (y1 <= y + (d - c) <= y2)
        and (x2 - x1 > 0 or (a == 0 and b == 0))
        and (y2 - y1 > 0 or (c == 0 and d == 0))
    ):
        print('Yes')
    else:
        print('No')
