n, k = map(int, input().split())
l, r = 0, int(1e9) + 1
m = -1
while l < r - 1:
    f = 0
    m = (l + r) // 2
    sm = 0
    i = 0
    v = m
    while v:
        sm += v
        i += 1
        v = int(m / pow(k, i))
    if sm >= n:
        r = m
    else:
        l = m
print(r)