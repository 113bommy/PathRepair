n, v = map(int, input().split())
if v > n:
    print(n)
else:
    c = (n - v) * (n - v + 1) // 2 - 1 + v
    print(c)
