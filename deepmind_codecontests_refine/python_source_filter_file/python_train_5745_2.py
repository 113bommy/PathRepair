t = int(input())
for j in range(t):
    n, m, k = map(int, input().split())
    f = True
    a = list(map(int, input().split()))
    i = 0
    while f and i < n - 1:
        if abs(a[i + 1] - a[i]) <= k or a[i] > a[i + 1]:
            m += a[i] - (a[i + 1] - k)
        elif a[i+1] - a[i] - k <= m:
            m -= a[i+1] - a[i] - k
        else:
            f = False
        i += 1
    if f:
        print('YES')
    else:
        print('NO')