a1, a2, k1, k2, n = int(input()), int(input()), int(input()), int(input()), int(input())
if k1 < k2:
    k1, k2 = k2, k1
    a1, a2 = a2, a1
ma = min(a1, n // k1)
ma += min((a2, (n - ma * k1) // k2))
print(max(0, n - a1 * (k1 - 1) - a2 * (k2 - 1)), ma)
