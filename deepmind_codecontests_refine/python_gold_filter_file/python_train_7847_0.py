x, y, xx = map(int, input().split())
cnt = 0
while max(x, y) < xx:
    if x < y:
        x, y = y, x
    l, r, m = 0, 4 * 10 ** 18, 0
    while r > l + 1:
        m = (l + r) // 2;
        if x >= m * x + y:
            l = m
        else:
            r = m
    if r == 4e18:
        print(-1)
        exit(0)
    cnt += r
    temp = x
    x = r * x + y
    y = temp
print(cnt)