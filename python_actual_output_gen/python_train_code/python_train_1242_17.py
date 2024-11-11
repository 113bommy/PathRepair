n, m = map(int, input().split())
print((m + (1 if m <= (n + 1) // 2 else -1)) if n != 1 else 1)
