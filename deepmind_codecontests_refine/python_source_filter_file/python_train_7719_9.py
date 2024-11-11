n, m = map(int, input().split())

if m <= 1:
    print(1)
elif m == 2:
    if n == 2:
        print(0)
    elif n == 3:
        print(1)
    else:
        print(2)
elif m < n // 2:
    print(m+1)
else:
    print(n - m)

