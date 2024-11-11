def C(m, n):
    res = 1
    if (n - m) < m:
        m = n - m
    for i in range(0, m):
        res *= n - i
        res /= i + 1
    return res
n = int(input())
print(C(5, n) + C(6, n) + C(7, n))
