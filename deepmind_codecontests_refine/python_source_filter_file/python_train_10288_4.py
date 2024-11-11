n = int(input())
xyh = [list(map(int, input().split())) for _ in range(n)]
xyh.sort(key=lambda x: x[2], reverse=True)
ans = []

for cx in range(101):
    for cy in range(101):
        x, y, h = xyh[0]
        ch = h + abs(x - cx) + abs(y - cy)
        if all([ch == max(h + abs(x - cx) + abs(y - cy), 0) for x, y, h in xyh[1:]]):
            ans = [cx, cy, ch]
            break
print(*ans, sep=' ')