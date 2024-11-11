n, k = [int(i) for i in input().split()]

m = (n // 2) // (k + 1)

print(m, k * m, n - (k + 1) * m)