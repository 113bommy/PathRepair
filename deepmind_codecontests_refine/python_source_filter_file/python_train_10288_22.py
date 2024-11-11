n = int(input())

xyhs = [list(map(int, input().split())) for _ in range(n)]
xyhs.sort(key=lambda i: i[2], reverse=True)

for cx in range(100):
    for cy in range(100):
        x, y, h = xyhs[0]
        ch = h + abs(cy - y) + abs(cx - x)

        if all([ch == max(h + abs(cy - y) + abs(cx - x), 0) for x, y, h in xyhs[1:]]):
            print(cx, cy, ch)
            exit()
