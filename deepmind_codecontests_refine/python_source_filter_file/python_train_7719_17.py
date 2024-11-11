n, m = map(int, input().split())

if n == m:
    print(0)
elif m == 0:
    print(1)
else:
    mid = n // 2
    if m >= mid:
        print(n - m)
    else:
        print(m)