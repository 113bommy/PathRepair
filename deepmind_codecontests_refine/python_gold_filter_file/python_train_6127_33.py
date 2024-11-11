n, m = map(int, input().split())
if m <= 2 * n:
    print(m // 2)
else:
    print(n + (m - 2 * n) // 4)
