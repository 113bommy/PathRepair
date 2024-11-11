n, m = map(int, input().split())

if 1 < m < n / 2:
    print(m)
elif m >= n / 2:
    print(n - m)
else:
    print(1)
