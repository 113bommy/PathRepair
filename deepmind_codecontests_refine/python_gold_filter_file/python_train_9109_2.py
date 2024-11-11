# HEY STALKER
n, x1, y1, x2, y2 = map(int, input().split())
l = [[0, 0]]
for _ in range(n):
    a1, b1 = map(int, input().split())
    a = ((a1 - x1) ** 2) + ((b1 - y1) ** 2)
    b = ((a1 - x2) ** 2) + ((b1 - y2) ** 2)
    l.append([a, b])
ans = 7e18
for t in l:
    r1 = t[0]
    r2 = 0
    for i in l:
        if r1 < i[0]:
            r2 = max(r2, i[1])
    ans = min(ans, r1 + r2)
print(ans)