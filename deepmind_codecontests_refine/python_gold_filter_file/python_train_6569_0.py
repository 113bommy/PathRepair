R = lambda: map(int, input().split())
n, h = R()
ps = []
for _ in range(n):
    l, r = R()
    ps.append([l, r])
l, c, res = 0, 0, 0
for r in range(n):
    c += (ps[r][0] - ps[r - 1][1]) if r > 0 else 0
    while c >= h:
        c -= (ps[l + 1][0] - ps[l][1])
        l += 1
    res = max(res, ps[r][1] - ps[l][0] + h - c)
print(res)