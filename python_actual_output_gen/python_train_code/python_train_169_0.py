R = lambda: map(int, input().split())
c1, c2, x, y = R()
l, r = c1 + c2, 2 * 10**9 + 7
while l < r:
    m = (l + r) // 2
    r1 = max(0, c1 - m // y - m // (x * y))
    r2 = max(0, c2 - m // x - m // (x * y))
    if m - m // x - m // y + m // (x * y) < r1 + r2:
        l = m + 1
    else:
        r = m
print(l)