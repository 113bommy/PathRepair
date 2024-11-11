m, n = map(int, input().split())
if m % 2 == 0:
    print(m // 2 * n)
else:
    if n % 2 == 0:
        print(n // 2 * n)
    else:
        print((m * n - 1) // 2)
            

