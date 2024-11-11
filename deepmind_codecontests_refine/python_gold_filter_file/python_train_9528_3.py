n = int(input())
otv1 = n * (n - 1) * (n - 2) // 6 + n * (n - 1) + n
otv2 = n * (n - 1) * (n - 2) * (n - 3) * (n - 4) // 120 + n * (n - 1) * (n - 2) * (n - 3) // 6 + n * (n - 1) * (n - 2) + n * (n - 1) * 2 + n
print(otv1 * otv2)