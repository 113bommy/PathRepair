n, k = map(int, input().split())
print((n // k)**3 + (~k & 1) * (n // (k // 2) - n // k)**3)
