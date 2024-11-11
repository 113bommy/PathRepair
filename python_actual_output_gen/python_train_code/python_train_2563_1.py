def voevoda(n, m):
    if n == 1:
        return m
    if n == 2:
        return (m - m % 4) + 2 * min(m % 4, 2)
    return (n * m + 1) // 2


N, M = [int(i) for i in input().split()]
print(voevoda(N, M))
