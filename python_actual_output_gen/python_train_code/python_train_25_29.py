def binp(x):
    l, r = -1, n
    while (r - l) > 1:
        m = (r + l) // 2
        if x < a[m]:
            r = m
        else:
            l = m
    return r


n = int(input())
a = list(map(int, input().split()))
y = binp(500000)
x1, x2 = 0, 0
if a[:y]:
    x1 = max(a[:y])
if a[y:]:
    x2 = min(a[y:])
print(max(x1 - 1, 1000000 - x2))
