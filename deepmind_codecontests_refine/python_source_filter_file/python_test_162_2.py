def check(a, m):
    tmp = a.copy()
    for i in range(n - 1, 1, -1):
        if tmp[i] < m:
            return False
        d = (tmp[i] - m) // 3
        if 3 * d > a[i]:
            d = a[i] / 3
        tmp[i - 1] += d
        tmp[i - 2] += 2 * d
    if tmp[0] < m or tmp[1] < m:
        return False
    return True


t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    l, r = min(a), max(a) + 1
    while r - l > 1:
        m = (l + r) // 2
        if check(a, m):
            l = m
        else:
            r = m
    print(l)