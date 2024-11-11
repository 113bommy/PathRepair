def solve(n, m, a, b):
    if n == 0:
        return 0
    res = 0
    if a >= m:
        res += (n-1) * n // 2 * (a // m)
        a %= m
    if b >= m:
        res += n * (b // m)
        b %= m
    p = (a*n + b) // m
    q = p*m - b
    return res + solve(p, a, m, a*n-q)

t = int(input())
for i in range(t):
    n, m, a, b = map(int, input().split())
    print(solve(n, m, a, b))