def R():
    return map(int, input().split())

n, m = R()
l = list(R())

a = [None] * n
b = [False] * n

for i in range(m - 1):
    j = l[i] - 1
    d = l[i + 1] - l[i]
    if d <= 0:
        d += n
    if a[j] != d:
        if a[j] is not None or b[d - 1]:
            print(-1)
            break
        a[j] = d
        b[d - 1] = True
else:
    j = 0
    for i in range(n):
        if a[i] is None:
            while b[j]:
                j += 1
            a[i] = j
            j += 1
    print(*a)
