n, m = map(int, input().split())

if n * 2 > m:
    print(m // 2)
else:
    print((m - 2*n) // 4 + n)