n, k = [int(i) for i in input().split()]

m = (n // 2) // (k + 1)

print(m, 2 * m, n - 3 * m)