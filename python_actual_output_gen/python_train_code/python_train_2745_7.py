def C(n, r, m):
    num, den = 1, 1
    for i in range(1, r + 1):
        num = num * (n - i + 1) % m
        den = den * i % m
    return (num * pow(den, m - 2, m)) % m

x, y = map(int, input().split())
m = (2*x - y) // 3
n = (-x + 2*y) // 3
if x + y % 3 != 0 or m < 0 or n < 0:
    print(0)
else:
    print(C(n + m, n, 10**9 + 7))