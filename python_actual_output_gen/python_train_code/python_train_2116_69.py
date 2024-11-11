n, m = map(int, input().split())

if n * 2 > m:
    print(n)
else:
    print((m - 2*n) // 4 + n)