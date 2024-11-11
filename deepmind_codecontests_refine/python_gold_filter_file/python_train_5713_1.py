a = [[0] * 14 for _ in range(14)]
while True:
    try:
        x, y, s = map(int, input().split(','))
    except:
        break
    x += 2
    y += 2
    for d in [(0, 0), (0, -1), (0, 1), (-1, 0), (1, 0)]:
        a[x + d[0]][y + d[1]] += 1
    if s >= 2:
        for d in [(1, 1), (1, -1), (-1, 1), (-1, -1)]:
            a[x + d[0]][y + d[1]] += 1
    if s == 3:
        for d in [(0, 2), (0, -2), (2, 0), (-2, 0)]:
            a[x + d[0]][y + d[1]] += 1
print(sum(a[i][2:12].count(0) for i in range(2, 12)))
print(max(max(a[i][2:12]) for i in range(2, 12)))