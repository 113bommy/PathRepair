n, m, k = map(int, input().split())
if k <= n:
    x = k + 1
    y = 1
else:
    x = n - (k - n) // (m - 1)
    if x % 2 == 0:
        y = (k - n) % (m - 1) + 2
    else:
        y = m - (k - n) % (m - 1)
print("{} {}".format(x, y))