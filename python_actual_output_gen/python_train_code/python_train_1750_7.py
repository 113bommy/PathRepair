n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
for i in range(1, n):
    a[i] += a[i - 1]
for i in range(m):
    l = 0
    r = n - 1
    while r - l > 1:
        m = (r + l) // 2
        if a[m] <= b[i]:
            l = m
        else:
            r = m
    if a[l] >= b[i]:
        print(l + 1, b[i])
    else:
        print(r + 1, b[i] - a[l])